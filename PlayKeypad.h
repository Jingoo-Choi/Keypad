#ifndef _PLAY_KEY_PAD_H_
#define _PLAY_KEY_PAD_H_

#include <Keypad.h>

class  PlayKeypad : public  Keypad {
  public:
    PlayKeypad(char* user_key_map, byte* row, byte* col, byte  numRows, byte  numCols);

    int getKeyNum();
    int getOldKeyNum();
    char getKeyChar();
    char getOldKeyChar();

    String  getKeyString(int);
    String  getKeyString(char ='*');
    String  getOldKeyString();

    int getKeyValue(char ='*');
  int getOldKeyValue();
                                          
  // 추가 보완 가능한 함수 : 키 입력 직접 구현 or 상속 라이브러리 코드 분석 필요                  
    //char  getActiveNum  (int condition_time);   // 단일 버튼 : 눌러져 있는 버튼 확인
    //String getActiveKeypad ( uint8_t buf[] );       // 복수 버튼 : 눌러져 있는 버튼 확인
                                           
  private:        
    char _old_key;
    int _old_key_num;
    String _old_key_str;
    uint32_t _old_key_value;
    uint32_t _start_time;
    bool _start_flag;                            
};

#endif
