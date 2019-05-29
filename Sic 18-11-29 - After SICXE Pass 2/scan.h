#include<iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include<vector>
#include "pass1.h"
#include "pass2.h"
#include "Literal_Adder_Loc_Counter.h"
#include"hex_inc_dec.h"
#include"instruction_find.h"
#include "String _To_Opcode_Fit_8.h"
#include"currentline_divide_strings.h"
#include "hex_indirect_addressing_changer.h"
#include "Obj_Code_Fix_Exced_6.h"
#include "Chek_if_Dec.H"
#include "Prog_Length.h"

#include "Symbol_Table.h"
#include "Literal_Table.h"
using namespace std;
#ifndef SCAN_H_DEF
#define SCAN_H_DEF
//string Current_Line_Without_Spac[4]; //this array store line without spacing like h1w1a start 1010 put it in pos 0 h1w1a pos 1 start (4 because we have label and inst and label and x if u have) mustn't have 4 string .....

void Pass_ONE(string File_Path);
void Pass_TWO(string File_Path);
void test();
#endif // SCAN_H_DEF
