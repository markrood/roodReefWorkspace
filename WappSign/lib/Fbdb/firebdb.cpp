#include <firebdb.h>
#include <Arduino.h>



void Firebdb::getKeys(){
  Serial.println("got to half");
    query.limitToLast(50);
Serial.print("Size of Folks = ");
Serial.println(sizeof(folks));

for (int i = 0; i < 16; i++){
String myStr = String(folks[i]);
  String path = "/Songs/2024/" + myStr + "/";
  Serial.println(path);    
    if (Firebase.ready()) //
    {
      //taskComplete = true;
  Firebase.getJSON(*fbdo,path , query);


      // Success, then try to read the JSON payload value
      /////////////////////////////////////////////////////////
      //FirebaseJson *json = data.to<FirebaseJson *>();
      //Print all object data
      //Serial.println((const char *)FPSTR("Pretty printed JSON data:"));
      FirebaseJson &json = fbdo->jsonObject();
      json.toString(Serial, true);

      size_t len = json.iteratorBegin();
      Serial.print("size of json is ");
      Serial.println(len);
     
      currentLen = len;
      FirebaseJson::IteratorValue value;
      
      if(folks[i] == "MarkDane"){

        MarkDane = new int[currentLen];
        MarkDane[0] = 999;
        for (size_t j = 0; j < len; j++)
        {
          value = json.valueAt(j);
          int val = value.value.toInt();
          MarkDane[j] = val;
          Serial.println(val);
        }
        delay(100);
      }else if(folks[i] == "MarkMckay"){
        MarkMckay = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          MarkMckay[j] = val;
          Serial.println(val);
        }
        
        delay(100);
      }else if(folks[i] == "MarkJeff"){
        MarkJeff = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          MarkJeff[j] = val;
          Serial.println(val);
        }
        delay(100);
      }else if(folks[i] == "CaseyKyle"){
        CaseyKyle = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          CaseyKyle[j] = val;
          Serial.println(val);
        }
        delay(100);
      }else if(folks[i] == "DaneJeffMckay"){
        DaneJeffMckay = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          DaneJeffMckay[j] = val;
          Serial.println(val);
        }
         delay(100);
      }else if(folks[i] == "DaneJeff"){
        DaneJeff = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          DaneJeff[j] = val;
          Serial.println(val);
        }
        delay(100);

      }else if(folks[i] == "JeffKyle"){
        JeffKyle = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          JeffKyle[j] = val;
          Serial.println(val);
        }
        delay(100);
      }else if(folks[i] == "Casey"){
        Casey = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          Casey[j] = val;
          Serial.println(val);
        }
        delay(100);
      }else if(folks[i] == "Chris"){
        Chris = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          Chris[j] = val;
          Serial.println(val);
        }
        delay(100);
      }else if(folks[i] == "Dane"){
        Dane = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          Dane[j] = val;
          Serial.println(val);
        }
        delay(100);
      }else if(folks[i] == "Eric"){
        Eric = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          Eric[j] = val;
          Serial.println(val);
        }
        
      }else if(folks[i] == "Jeff"){
        Jeff = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          Jeff[i] = val;
          Serial.println(val);
        }
        
        delay(100);
      }else if(folks[i] == "Kyle"){
        Kyle = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          Kyle[j] = val;
          Serial.println(val);
        }
        delay(100);
      }else if(folks[i] == "Mark"){
        Mark = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          Mark[j] = val;
          Serial.println(val);
        }
        delay(100);
    }else if(folks[i] == "McKay"){
      McKay = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          McKay[j] = val;
          Serial.println(val);
        }
        delay(100);
    }else if(folks[i] == "Nat"){
      Nat = new int[currentLen];
        for (size_t j = 0; j < len; j++)
        {
  
          value = json.valueAt(j);
          int val = value.value.toInt();
          Nat[j] = val;
          Serial.println(val);
        }
        delay(100);
      }

    }
    else
    {
      // Failed to get JSON data at defined database path, print out the error reason
      Serial.println(fbdo->errorReason());
    }
}
}


void Firebdb::addFB(FirebaseData *fbo){
    fbdo =  fbo;

}

void Firebdb::writeKeyToDb(String key, String name){  
  FirebaseData fd;
      String parentPath = "WappSongs/"+ key; 
  FirebaseJson json;
  json.toString(Serial, true);
  json.set("Year", "2024");
  json.set("Person", name);
  Firebase.setJSON(fd,parentPath,json);
  delay(100);
}