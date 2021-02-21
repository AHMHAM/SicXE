#include<string>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#ifndef HEX_INC_DEC_H
#define HEX_INC_DEC_H
string _String_Hex_INC_X(string Location,string OFFSET,string DecL_OFFSET);// Function Convert String To Hex Number And Inc It with x and return hex string DEC_OFFSET IT FOR RESB AND RESW
string _String_Hex_DEC_X(string HEX_1,string HEX_2);// Function Convert String To Hex Number And Dec It with x and return hex string
int _Str_To_INT(string String);
string _Int_To_Hex_STR(int Hex_Number_In_INT,int Old_String_SIZE);
int _Hex_String_To_INT(string String);
bool is_number(string test_str);
#endif // HEX_INC_H
