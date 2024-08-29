#include "utilITY.h"

#define MAX_LENGTH 15;


Utility::Utility(WappSign *si){
    sign = si;
}

long Utility::generateHash(String str){
long result = 0;
for (int i = 0; i < str.length(); i++){
   result += pow(27, 15 - i - 1)*(1 + str.charAt(i) - 'a');
}
   return result;
}

int Utility::getHour(){
	configTime(gmtOffset_sec, 0, ntpServer);
	if(!getLocalTime(&timeinfo)){
  	Serial.println("Failed to obtain time");
  return 9;
}
	char timeHour[3];
	strftime(timeHour,3, "%H", &timeinfo);
	String strHour = String(timeHour);
	return strHour.toInt();


}

String Utility::readFile(fs::FS &fs, const char * path){
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

void Utility::writeFile(fs::FS &fs, const char * path, const char * message){
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

bool Utility::checkSunset(int sunset){
    k++;

        if(k == 15){
          //String strHour = volRest->getHour();
        
          int hour = getHour();
          Serial.print("hhhhour is ");
          Serial.println(hour);
          String oldHour = readFile(LittleFS,"/hour.txt");
          if(hour >=6 && hour <sunset){
            if(!setDaytime){
              Serial.print("Time hour is ");
              Serial.println(hour);
              Serial.print("Sunset is ");
              Serial.println(sunset);
              setDaytime = true;
              setNightime = false;
              sign->setBrightness(40);
              daytime = true;
              nightime - false;
              }
        }
        if(hour <6 || hour >sunset){
          if(!setNightime){
              Serial.print("Time hour is ");
              Serial.println(hour);
              Serial.print("Sunset issss ");
              Serial.println(sunset);
            setDaytime = false;
            setNightime = true;
            sign->setBrightness(20);
            daytime = false;
            nightime =true;
          }
        }
        int thisHour = getHour();
        oldHour = readFile(LittleFS,"/hour.txt");
        int oHour = oldHour.toInt();
        if(oHour != thisHour){
          String strHour = String(thisHour);
          writeFile(LittleFS,"/hour.txt",strHour.c_str());
          if(thisHour == 2){
            ESP.restart();
          }
        }
          k=0;
          return true;
        }
        return false;
}