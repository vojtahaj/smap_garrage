#include <NewPing.h>

int trigPinGarrage = 2;
int echoPinGarrage = 3;
//#define trigPinBeforeGarrage 4;
//#define echoPinBeforeGarrage 5;
const int doorOpenPin = 6;
const int doorClosePin = 7;

const int DOOR_OPEN = 0;
const int DOOR_CLOSE = 1;
const int DOOR_IN_PROGRESS = 2;

int maxLengthGarrage = 400;
int maxLengthBeforeGarrage = 200;
int carHeight = 150;

NewPing garrageSource(trigPinGarrage, echoPinGarrage, maxLengthGarrage);
NewPing beforeGarrageSource(trigPinGarrage, echoPinGarrage, maxLengthBeforeGarrage);
float garrageLength = 0;
float beforeGarrageLength =0;

int doorState;

void setup() {
  // put your setup code here, to run once:
  pinMode(doorOpenPin, INPUT);
  pinMode(doorClosePin, INPUT);

  Serial.begin(9600);

  //kontrola vrat
//  doorState = checkDoor();
}

void loop() {
  
  
//  Serial.println("test");
//  digitalRead(doorOpenPin)
  //zkontroluj misto pred garazi

  //zkontroluj jestli je misto v garazi
  if (doorState == DOOR_OPEN) {
  //je misto zkontroluj misto v  garazi a parkuj
  //checkBeforeGarrage();
    if(isGarrageFree()){
      Serial.println("GFREE");
      //setParking();
    }
    else {
    //neni misto
    
    if(isGas()){
      //auto parkuje
      if (garrageSource.ping_cm() >= 5) {
        Serial.println("STOP");
      }
      
    }
    else {
        //auto neparkuje, je tam prekazka 
        Serial.println("BARIER");   
        Serial.print("GL");
        Serial.println(garrageSource.ping_cm());
        Serial.println("GSTOP");
      } 
  
  //v garazi je nejaky objekt
  
  }
  }

 //kdyz jsou zavrene dvere
 if(doorState == DOOR_CLOSE){
  //checkBeforeGarrage();
  //pokud je kratsi nez default length, tak nejaky error
 }
  
  //neni misto? Je to staticke
    //ano - je tam predmet neparkuj
    //ne - smrdi tam CO?
        //ano - auto parkuje
        //ne - nejspise se tam nekdo hejbe 


  Serial.print("v garazi: ");
  Serial.println(garrageSource.ping_cm());
  Serial.print("pred garazi: ");
  Serial.println(beforeGarrageSource.ping_cm());
  
  delay(1000);
}


bool isGarrageFree(){
  if (garrageSource.ping_cm() > 350){
    return true;
  }
  else {
    return false;
  }
}
bool isMove(bool garrage) {
int radar;
if (garrage) {
  radar = garrageSource.ping_cm();
} 
else radar = beforeGarrageSource.ping_cm();
}
void parking(){
   //prepne ultrazvuk v garazi a bude hlasit jak je daleko od zadku
   //na 5cm pokyn pro zastaveni
   //vyres vzdalenost > 350cm tak a
  }

void checkBeforeGarrage(){
  int lengthRadar = beforeGarrageSource.ping_cm();
  if (lengthRadar < maxLengthBeforeGarrage) {
//    isMove(false);
    if (lengthRadar > carHeight - 5 || lengthRadar < carHeight - 5) {
      //je tam neco jineho nez auto
      // stuj
      Serial.println("BGSTOP");
    }
  }
   //pohrat si s millis at zjistime, jestli se tam neco hybe
   //hybe li se, tak je to asi auto
   // je vzdalenost +- stejna jako vyska auta - je to auto
   // else je to clovek 
  }

bool isGas(){
  //zjisti, jestli je v garazi zvysena koncentrace CO
  return false;
}
int checkDoor(){
  if(digitalRead(doorOpenPin) == HIGH && digitalRead(doorClosePin) == LOW && doorState != DOOR_OPEN){
    //dvere otevrene
    Serial.println("DOPEN");
   return doorState = DOOR_OPEN;
  }
  if(digitalRead(doorOpenPin) == LOW && digitalRead(doorClosePin) == HIGH && doorState != DOOR_CLOSE){
    //dvere zavrene
    Serial.println("DCLOSE");
    return doorState = DOOR_CLOSE;
  }
  if(digitalRead(doorOpenPin) == HIGH && digitalRead(doorClosePin) == LOW && doorState != DOOR_IN_PROGRESS){
    //dvere v mezistavu
    Serial.println("DOC");
    return doorState = DOOR_IN_PROGRESS;
  }
  //vrata otevrena?
      //RGBled zelena
      //garrageDoor = OPEN;
   //vrata zavrena
    //RGBled cervena
    //garrageDoor= CLOSE;
   //pak jsou vrata v nejakem mezistavu (oba vstupy otevrene)
   //a to RGBOranzova garrageDoor = IN_PROGRESS
   }
