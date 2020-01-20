#include "PlayKeypad.h"

PlayKeypad::PlayKeypad(char* user_key_map, byte* row, byte* col, byte  numRows, byte  numCols)
  : Keypad(user_key_map, row, col, numRows, numCols) {
  this->_old_key = 0;
  this->_old_key_num = -1;
  this->_start_time = 0;
  this->_start_flag = false;
}

int PlayKeypad::getKeyNum() {
  char tmp = this->getKey();
  int ret = 0;
  
  if ((tmp >= 48) && (tmp <= 57)) {
    ret = tmp - 48;
    _old_key_num = ret;
  }
  else if ((tmp == 35) || (tmp == 42)) ret = tmp;
  else ret = -1; 
  return ret;
}

int PlayKeypad::getOldKeyNum() {
  return _old_key_num;
}

char PlayKeypad::getKeyChar() {
  char key = this->getKey();
  if(key) _old_key = key;
  return key;
}

char PlayKeypad::getOldKeyChar() {
  return _old_key;
}

String PlayKeypad::getKeyString(int nums) {
  String ret;
  int cnt = 0;
  char key = 0;
  while (cnt != nums) {
    key = this->getKey();
    if (key) {
      ret += String(key);
      cnt++;
    }
  }
  _old_key_str = ret;
  return ret;
}

String PlayKeypad::getKeyString(char flag) {
  String ret;
  char key = 0;
  while (key != flag) {
    key = this->getKey();
    if (key) {
      ret += String(key);
    }
  }
  _old_key_str = ret;
  return ret;
}

String PlayKeypad::getOldKeyString() {
  return _old_key_str;
}

int PlayKeypad::getKeyValue(char flag) {
  char char_str[20] = { 0 };
  char key = 0;
  int ret = 0;
  uint8_t index = 0;

  while (key != flag) {
    key = this->getKey();
    if (key) {
      char_str[index++] = key;
    }
    if (index > 20) return -1;
  }
  ret = atoi(char_str);
  _old_key_value = ret;
  return ret;
}

int PlayKeypad::getOldKeyValue() {
  return _old_key_value;
}

//char PlayKeypad::getActiveNum(int condition_time) {
//  char key = this->getKey();
//
//  if (key != _old_key) {
//    _old_key = key;
//    _start_time = 0;
//    _start_flag = false;
//    return 0;
//  }
//
//  if (_start_flag == false) {
//    _start_time = millis();
//    _start_flag = true;
//  }
//
//  if ((millis() - _start_time) < condition_time) {
//    return 0;
//  }
//  else {
//    return key;
//  }
//}
