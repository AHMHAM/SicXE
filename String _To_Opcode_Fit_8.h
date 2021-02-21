#include "hex_inc_dec.h"
#include<string>
#include<iostream>
#ifndef STRING_TO_OPCODE_FIT_8_H
#define STRING_TO_OPCODE_FIT_8_H
using namespace std;
string String_To_Opcode(string String);
string String_To_Opcode_Change_Size_TO_X(string Current_Op_code,int x,char place_holder);
string String_Decrease_SIZE(string Current_strig,char Remove_place_holder);
#endif // STRING_TO_OPCODE_FIT_8_H
