#include<string>
#include<iostream>
#include"instruction_find.h"

using namespace std;
#ifndef OBJECT_CODE_FALGS_H_DEF
#define OBJECT_CODE_FALGS_H_DEF
string Flags_n_i(string label);
string Flags_x_b_p(string label,string next_location,string format,string hex_disp);
#endif // OBJECT_CODE_FALGS_H_DEF
