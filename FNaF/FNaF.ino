#include <LCD5110_Basic.h>

float battery = 100;

bool leftDoor = false;
bool rightDoor = false;

bool isBonnieThere = false;
bool isChicaThere = false;
bool isFreddyThere = false;
bool isFoxyThere = false;

bool firstLoop = false;
bool secondLoop = false;
bool thirdLoop = false;
bool fourthLoop = false;
bool fifthLoop = false;
bool sixthLoop = false;
bool seventhLoop = false;
bool eighthLoop = false;
bool ninthLoop = false;

#define leftDoorLed 7
#define rightDoorLed 6

#define batteryled1 5
#define batteryled2 4
#define batteryled3 3
#define batteryled4 2
#define batteryled5 13

#define lightLeftButton A3
#define lightRightButton A0

#define doorLeftButton A2
#define doorRightButton A1

LCD5110 myGLCD(8, 9, 10, 11, 12);

extern uint8_t SmallFont[];

extern uint8_t Bonnie[];
extern uint8_t Office[];
extern uint8_t Chica[];
extern uint8_t Freddy[];
extern uint8_t Foxy[];
extern uint8_t LeftEmpty[];
extern uint8_t RightEmpty[];
extern uint8_t BonnieJumpscare[];
extern uint8_t ChicaJumpscare[];
extern uint8_t FoxyJumpscare[];
extern uint8_t FreddyJumpscare[];
extern uint8_t LeftClosed[];
extern uint8_t RightClosed[];
extern uint8_t Win[];

void setup() {
  Serial.begin(9600);

  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setContrast(60);
  myGLCD.setFont(SmallFont);

  pinMode(leftDoorLed, OUTPUT);
  pinMode(rightDoorLed, OUTPUT);
  pinMode(batteryled1, OUTPUT);
  pinMode(batteryled2, OUTPUT);
  pinMode(batteryled3, OUTPUT);
  pinMode(batteryled4, OUTPUT);
  pinMode(batteryled5, OUTPUT);

  pinMode(lightLeftButton, INPUT);
  pinMode(lightRightButton, INPUT);
  pinMode(doorLeftButton, INPUT);
  pinMode(doorRightButton, INPUT);

  myGLCD.drawBitmap(0, 0, Office, 84, 48);

  digitalWrite(batteryled1, HIGH);
  digitalWrite(batteryled2, HIGH);
  digitalWrite(batteryled3, HIGH);
  digitalWrite(batteryled4, HIGH);
  digitalWrite(batteryled5, HIGH);
}

void loop() {
  delay(750);

  if (leftDoor == true) {
    battery = battery - 0.12;
  }
  if (rightDoor == true) {
    battery = battery - 0.12;
  }
  battery = battery - 0.05;

  if (battery > 80) {
    digitalWrite(batteryled1, HIGH);
    digitalWrite(batteryled2, HIGH);
    digitalWrite(batteryled3, HIGH);
    digitalWrite(batteryled4, HIGH);
    digitalWrite(batteryled5, HIGH);
  } else if (battery > 60) {
    digitalWrite(batteryled1, LOW);
    digitalWrite(batteryled2, HIGH);
    digitalWrite(batteryled3, HIGH);
    digitalWrite(batteryled4, HIGH);
    digitalWrite(batteryled5, HIGH);
  } else if (battery > 40) {
    digitalWrite(batteryled1, LOW);
    digitalWrite(batteryled2, LOW);
    digitalWrite(batteryled3, HIGH);
    digitalWrite(batteryled4, HIGH);
    digitalWrite(batteryled5, HIGH);
  } else if (battery > 20) {
    digitalWrite(batteryled1, LOW);
    digitalWrite(batteryled2, LOW);
    digitalWrite(batteryled3, LOW);
    digitalWrite(batteryled4, HIGH);
    digitalWrite(batteryled5, HIGH);
  } else if (battery > 0) {
    digitalWrite(batteryled1, LOW);
    digitalWrite(batteryled2, LOW);
    digitalWrite(batteryled3, LOW);
    digitalWrite(batteryled4, LOW);
    digitalWrite(batteryled5, HIGH);
  } else if (battery < 1) {
    digitalWrite(batteryled1, LOW);
    digitalWrite(batteryled2, LOW);
    digitalWrite(batteryled3, LOW);
    digitalWrite(batteryled4, LOW);
    digitalWrite(batteryled5, LOW);
    goto FreddyJumpscare;
  }

  goto doNotGo;

BonnieJumpscare:  //goto's
  myGLCD.clrScr();
  myGLCD.drawBitmap(0, 0, BonnieJumpscare, 84, 48);
  delay(100000);
  goto BonnieJumpscare;

ChicaJumpscare:
  myGLCD.clrScr();
  myGLCD.drawBitmap(0, 0, ChicaJumpscare, 84, 48);
  delay(100000);
  goto ChicaJumpscare;

FoxyJumpscare:
  myGLCD.clrScr();
  myGLCD.drawBitmap(0, 0, FoxyJumpscare, 84, 48);
  delay(100000);
  goto FoxyJumpscare;

FreddyJumpscare:
  myGLCD.clrScr();
  myGLCD.drawBitmap(0, 0, FreddyJumpscare, 84, 48);
  delay(100000);
  goto FreddyJumpscare;

Win:
  myGLCD.clrScr();
  myGLCD.drawBitmap(0, 0, Win, 84, 48);
  delay(100000);
  goto Win;

doNotGo:

  if (battery < 10) {
    eighthLoop = false;
    ninthLoop = true;
    Serial.println("NinthLoop");
  } else if (battery < 20) {
    seventhLoop = false;
    eighthLoop = true;
    Serial.println("EighthLoop");
  } else if (battery < 30) {
    sixthLoop = false;
    seventhLoop = true;
    Serial.println("SeventhLoop");
  } else if (battery < 40) {
    fifthLoop = false;
    sixthLoop = true;
    Serial.println("SixthLoop");
  } else if (battery < 50) {
    fourthLoop = false;
    fifthLoop = true;
    Serial.println("FifthLoop");
  } else if (battery < 60) {
    thirdLoop = false;
    fourthLoop = true;
    Serial.println("FourthLoop");
  } else if (battery < 70) {
    secondLoop = false;
    thirdLoop = true;
    Serial.println("ThirdLoop");
  } else if (battery < 80) {
    firstLoop = false;
    secondLoop = true;
    Serial.println("SecondLoop");
  } else if (battery < 90) {
    firstLoop = true;
    Serial.println("FirstLoop");
  }

  if (firstLoop == true) {  //Loops

    isBonnieThere = true;
    isChicaThere = false;
    isFreddyThere = false;
    isFoxyThere = false;

    if (battery < 84 && leftDoor == false) {
      goto BonnieJumpscare;
    }
  }

  if (secondLoop == true) {

    isBonnieThere = false;
    isChicaThere = true;
    isFreddyThere = false;
    isFoxyThere = false;

    if (battery < 74 && rightDoor == false) {
      goto ChicaJumpscare;
    }
  }

  if (thirdLoop == true) {

    isBonnieThere = true;
    isChicaThere = false;
    isFreddyThere = false;
    isFoxyThere = false;

    if (battery < 64 && leftDoor == false) {
      goto BonnieJumpscare;
    }
  }

  if (fourthLoop == true) {

    isBonnieThere = false;
    isChicaThere = false;
    isFreddyThere = false;
    isFoxyThere = false;

    if (battery < 58) {
      isFoxyThere = true;
    }

    if (battery < 54 && leftDoor == false) {
      goto FoxyJumpscare;
    } else if (battery < 54 && leftDoor == true) {
      battery = battery - 4;
    }
  }

  if (fifthLoop == true) {

    isBonnieThere = false;
    isChicaThere = false;
    isFreddyThere = false;
    isFoxyThere = false;
  }

  if (sixthLoop == true) {

    isBonnieThere = false;
    isChicaThere = false;
    isFreddyThere = true;
    isFoxyThere = false;

    if (battery < 34 && rightDoor == false) {
      goto FreddyJumpscare;
    }
  }

  if (seventhLoop == true) {

    isBonnieThere = false;
    isChicaThere = false;
    isFreddyThere = false;
    isFoxyThere = false;
  }

  if (eighthLoop == true) {

    isBonnieThere = true;
    isChicaThere = false;
    isFreddyThere = false;
    isFoxyThere = false;

    if (battery < 14 && leftDoor == false) {
      goto BonnieJumpscare;
    }
  }

  if (ninthLoop == true) {

    isBonnieThere = false;
    isChicaThere = false;
    isFreddyThere = false;
    isFoxyThere = false;

    if (battery < 4) {
      goto Win;
    }
  }

  if (digitalRead(lightLeftButton) == true) {  //Lights

    if (leftDoor == true) {
      myGLCD.drawBitmap(0, 0, LeftClosed, 84, 48);
    } else if (isBonnieThere == true) {
      myGLCD.drawBitmap(0, 0, Bonnie, 84, 48);
    } else if (isFoxyThere == true) {
      myGLCD.drawBitmap(0, 0, Foxy, 84, 48);
    } else {
      myGLCD.drawBitmap(0, 0, LeftEmpty, 84, 48);
    }

  } else if (digitalRead(lightRightButton) == true) {

    if (rightDoor == true) {
      myGLCD.drawBitmap(0, 0, RightClosed, 84, 48);
    } else if (isChicaThere == true) {
      myGLCD.drawBitmap(0, 0, Chica, 84, 48);
    } else if (isFreddyThere == true) {
      myGLCD.drawBitmap(0, 0, Freddy, 84, 48);
    } else {
      myGLCD.drawBitmap(0, 0, RightEmpty, 84, 48);
    }

  } else {
    myGLCD.drawBitmap(0, 0, Office, 84, 48);
  }



  if (digitalRead(doorLeftButton) == true) {  //Door statements

    if (leftDoor == true) {
      leftDoor = false;
      digitalWrite(leftDoorLed, LOW);
      myGLCD.drawBitmap(0, 0, LeftEmpty, 84, 48);
      delay(1500);
      myGLCD.drawBitmap(0, 0, Office, 84, 48);
    } else if (leftDoor == false) {
      leftDoor = true;
      digitalWrite(leftDoorLed, HIGH);
      myGLCD.drawBitmap(0, 0, LeftClosed, 84, 48);
      delay(1500);
      myGLCD.drawBitmap(0, 0, Office, 84, 48);
    }

  } else if (digitalRead(doorRightButton) == true) {

    if (rightDoor == true) {
      rightDoor = false;
      digitalWrite(rightDoorLed, LOW);
      myGLCD.drawBitmap(0, 0, RightEmpty, 84, 48);
      delay(1500);
      myGLCD.drawBitmap(0, 0, Office, 84, 48);
    } else if (rightDoor == false) {
      rightDoor = true;
      digitalWrite(rightDoorLed, HIGH);
      myGLCD.drawBitmap(0, 0, RightClosed, 84, 48);
      delay(1500);
      myGLCD.drawBitmap(0, 0, Office, 84, 48);
    }
  }

  Serial.print("Battery: ");
  Serial.println(battery, 2);
}