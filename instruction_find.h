#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include<sstream>
#include "Chek_if_Dec.H"
#include"hex_inc_dec.h"
#include "String _To_Opcode_Fit_8.h"
using namespace std;
#ifndef INST_H
#define INST_H
const string HEX_ONE ="0001";
const string HEX_TWO ="0002";
const string HEX_THREE ="0003";
const string HEX_FOUR ="0004";

const string FORMAT_ONE ="1";
const string FORMAT_TWO ="2";
const string FORMAT_THREE ="3";
const string FORMAT_FOUR ="4";
string _Instruction_Found_Get_INST(string current_string);
string _Instruction_Get_FORMAT(string current_string);
bool _Instruction_Found_Get_Location_Count_INC(string &Prog_Loc_Counter,string (&Current_Line_Without_Spac)[4],int Instruction_Loc);
#endif // INST_H
