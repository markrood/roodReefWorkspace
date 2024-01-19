#include <Arduino.h>
#include <WiFi.h>
//needed for library
#include <ESPAsyncWebServer.h>
#include <ESPAsyncWiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <WebSerial.h>
//#include <AsyncElegantOTA.h>
#include "FS.h"
#include "SPIFFS.h"
#include <AsyncElegantOTA.h>

//testing
#include "fishScheduler.h"
#include "fbdb.h"
#include "ato.h"
#include "awc.h"
#include "text.h"


///


AsyncWebServer server(80);
DNSServer dns;
//unsigned long ota_progress_millis = 0;
///////


FishSched *mySched;
Database *db;
Ato *ato;
Awc *awc;
Text *text;
int test = 0;

int yr = 0;
String yrStr = "";
int mo = 0;
String moStr = "";
int da = 0;
String daStr = "";
bool aFlagWasSetInLoop = false;
bool blueDosed = false;
bool midnightDone = false;
bool atoStarted = false;
bool atoRunning = false;
bool atoPending = false;
bool atoRan = false;
bool awcStarted = false;
bool awcRunning = false;
bool awcPending = false;
bool awcRan = false;

int z = 0;
float atoRunTime = 0;

// put function declarations here:
void configModeCallback (AsyncWiFiManager *myWiFiManager);

void checkAtoAwcSched(int i);
void setDate();

String readFile(fs::FS &fs, const char * path){
    Serial.printf("Reading file: %s\r\n", path);

    File file = fs.open(path);
    if(!file || file.isDirectory()){
        Serial.println("- failed to open file for reading");
        return "";
    }

    Serial.println("- read from file:");
    String ret = file.readString();
    
    file.close();
    return ret;
}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\r\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("- failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("- file written");
    } else {
        Serial.println("- write failed");
    }
    file.close();
}


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
    ///////////////////Start WiFi ///////////////////////////////////////
  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  AsyncWiFiManager wifiManager(&server, &dns);
  //reset settings - for testing
  //wifiManager.resetSettings();
  //wifiManager.setSTASt();aticIPConfig(IPAddress(192,168,1,175), IPAddress(192,168,1,1), IPAddress(255,255,255,0), IPAddress(192,168,1,1), IPAddress(192,168,1,1));
  //set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wifiManager.setAPCallback(configModeCallback);

  //fetches ssid and pass and tries to connect
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP"
  //and goes into a blocking loop awaiting configuration
  //Serial.println("got here");
  if (!wifiManager.autoConnect("Template")) {
    Serial.println("failed to connect and hit timeout");
    Serial.println("restarting esp");
    //reset and try again, or maybe put it to deep sleep
    ESP.restart();
    delay(1000);
  }
  delay(50);
  //Serial.print("FreeHeap is :");
  //Serial.println(ESP.getFreeHeap());
  delay(50);
  //if you get here you have connected to the WiFi
  Serial.println("connected...yeey :)");

  Serial.println("local ip");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Hi! I am ESP32.");
  });

    AsyncElegantOTA.begin(&server);


  server.begin();
 WebSerial.begin(&server);

  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

 delay(100);
  db  = new Database();
  db->initDb();
 mySched = new FishSched();
 mySched->updateMyTime();
 ato = new Ato();
 awc = new Awc();
 text = new Text();
 //TODO need to finish adding all the scheduler stuff  tons
 setDate();
while(!db->setEvents(1)){
  Serial.print("x");
  delay(10000);
}  
  int rst = text->sendHttp("Heartbeat");
  //Serial.print("return from http is ");
  //Serial.println(rst);

 delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  mySched->setNowTime(); //initializes time MUST DO THIS
  mySched->tick(); //sets hour
  mySched->tock();//sets minute
  //Serial.println("Just getting for flag for loop");

  for(int i= 0;i<37;i++){
    //mySched->printArray();
      int flagSet = mySched->isFlagSet(i);
      
      if(flagSet == 1){
        /*Serial.print("Flag set is number ");
        Serial.print(i);
        Serial.print(" ");*/

          checkAtoAwcSched(i);

      }else{
        //Serial.println("flag not set anymore!");
        atoRan = false;
        awcRan = false;
        
        

      }

  }
  if(aFlagWasSetInLoop) {
    aFlagWasSetInLoop = false;
  }else {
    blueDosed = false;

  }

z++;
if(z== 25){
  WebSerial.print(".");
  Serial.print(".");
  z=0;
}
  long temp = 0;
  String strTemp = String(temp);
  writeFile(SPIFFS, "/atoFill.txt", strTemp.c_str());
  delay(5000);
  String daileyAwcFill = readFile(SPIFFS, "/awcdailyfill.txt");
  //Serial.println(daileyAwcFill);
  delay(1000);
}

// put function definitions here:
void configModeCallback (AsyncWiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  //myWiFiManager->startConfigPortal("ATOAWC");addDailyDoseAmt
  //myWiFiManager->autoConnect("DOSER");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());

}

void setDate(){
  mySched->syncTime();
  yr = mySched->getCurrentYear();
  yr = yr;
  yrStr = String(yr);
  Serial.print("Year is: ");
  Serial.println(yrStr);
  mo = mySched->getCurrentMonth();
  Serial.print("Month is: ");
  Serial.println(mo);

  da = mySched->getCurrentDay();
  daStr = String(da-1);  //i need the day for save to db be the day before since i save at midnight
  Serial.print("YesterDay is: ");
  Serial.println(daStr);
 
  

}

/*
void checkAtoAwcSched(int i){
		  if(awcRunning && !atoPending && !atoRan){
			    atoPending = true;
			    Serial.println("ato is pending");
			  }else if (!awcRunning && atoPending){
			    atoPending = false;
			  }else if(!awcRunning && !atoPending){
			    if((db->isThisEventAtoAwcSet(i ,0)) && !atoRan){
			      atoStarted = true;
			      atoRunning = ato->doAto();
			      //if(ato->atoFinished) 
			      if(atoStarted && atoRunning){
			      }else{
			        if(!awcPending){
                
			          mySched->setFlag(i,0);
                 Serial.print("flag we are reseting int Ato is ");
                 Serial.println(i);
			          atoRan = false;
			          awcRan = false;
			        }
			        atoStarted = false;
			        atoRunning = false;
			        atoRan = true;
			      }
			    }
			    }
			    if ((db->isThisEventAtoAwcSet(i, 1)) && !awcRan){
			      if(atoRunning && !awcPending){
			        awcPending = true;
			        Serial.println("awc pending");
			      }else if (!atoRunning && awcPending){
			        awcPending = false;
			      }
			      if(!atoRunning && !awcPending){
			        awcStarted = true;
			        awcRunning = awc->doAwc(); 
			        if(awcStarted && awcRunning){
			        }else{
			          if(!atoPending ){
                  //awc->setI(0);
			           mySched->setFlag(i,0);
                 Serial.print("flag we are reseting in Awcis ");
                 Serial.println(i);
			           awcRan = false;
			           atoRan = false;
			          }
			          awcStarted = false;
			          awcRunning = false;
			          awcRan = true;
			        }
			      }
          }
}
*/

	void checkAtoAwcSched(int x){
		  if(awcRunning && !atoPending && !atoRan){
			    //atoPending = true;
			    //Serial.println("ato is pending");
			  }else if (!awcRunning && atoPending){
			    atoPending = false;
			  }else if(!awcRunning && !atoPending){
			    if((db->isThisEventAtoAwcSet(x ,0)) && !atoRan){
			      atoStarted = true;
			      atoRunning = ato->doAto();
			      //if(ato->atoFinished) 
			      if(atoStarted && atoRunning){
              ;//Serial.print("awc ");
			      }else{
			        if(!awcPending){
			          mySched->setFlag(x,0);
                //Serial.println("!!!!! set flag to 0");
			          //atoRan = false;
			          awcRan = false;
                atoPending = false;
                atoRunTime = ato->getAtoRunTime(); 
                String atoFillTotal  = readFile(SPIFFS, "/atoFill.txt");
                float fillLong = atoFillTotal.toFloat();
                float total = fillLong + fillLong;
                String strTotal = String(total);
                writeFile(SPIFFS, "/atoFill.txt", strTotal.c_str());

                

			        }
			        atoStarted = false;
			        atoRunning = false;
			        atoRan = true;
			      }
			    }
			    }
			    if ((db->isThisEventAtoAwcSet(x, 1)) && !awcRan){
			      if(atoRunning && !awcPending){
			        awcPending = true;
			        Serial.println("awc pending");
			      }else if (!atoRunning && awcPending){
			        awcPending = false;
			      }
			      if(!atoRunning && !awcPending){
			        awcStarted = true;
			        awcRunning = awc->doAwc(); 
			        if(awcStarted && awcRunning){
                ;//Serial.print("awc ");
			        }else{
			          if(!atoPending ){
			           mySched->setFlag(x,0);
                //Serial.println("!!!!! set flag to 0");
			           //awcRan = false;
			          // atoRan = false;
			          }
			          awcStarted = false;
			          awcRunning = false;
			          awcRan = true;
			        }
			      }

		

	}
	}
