#include "PlayKeypad.h"

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3}; //connect to the column pinouts of the keypad

PlayKeypad playkeypad = PlayKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(playkeypad.waitForKey());  
//  Serial.println(playkeypad.isPressed('2'));
  
//  char key = playkeypad.getKey();// Read the key
//  
//  // Print if key pressed
//  if (key){
//    Serial.print("Key Pressed : ");
//    Serial.println(key);
//  }

//    int key_int = key;
//  if (key_int){
//    Serial.print("Key_int Pressed : ");
//    Serial.println(key_int);
//  }

//    int key_int2 = playkeypad.getKeyNum();
//    if(key_int2 >=0) {
//    Serial.print("[2] Key_int Pressed : ");
//    Serial.println(key_int2);
//    Serial.println(playkeypad.getOldKeyNum());
//    }
//
//    int tmp = playkeypad.getOldKeyNum();
//    Serial.print("Old Key Num : ");
//    Serial.println(tmp);

//    char tmp1 = playkeypad.getKeyChar();
//    if(tmp1){
//    Serial.print("Key Char : ");
//    Serial.println(tmp1);
//    }
//
//    char tmp2 = playkeypad.getOldKeyChar();
//    Serial.print("Old Key Char : ");
//    Serial.println(tmp2);

//      char tmp3 = playkeypad.getActiveNum  (1000);
//      if(tmp3){
//        Serial.print("Key Char : ");
//        Serial.println(tmp3);
//      }

//        String tmp4 = playkeypad.getKeyString(4);
//        if(tmp4) {
//          Serial.println(tmp4);
//          Serial.println(playkeypad.getOldKeyString());
//        }

//        String tmp5 = playkeypad.getKeyString('*');
//        if(tmp5) {
//          Serial.println(tmp5);
//          Serial.println(playkeypad.getOldKeyString());
//        }

//  int tmp6 = playkeypad.getKeyValue('*');
//  if(tmp6) {
//    Serial.println(tmp6);
//  }
}
