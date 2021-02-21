#include <string>
#include<iostream>
#include <vector>
#include "Chek_if_Dec.H"

#include "Symbol_Table.h"
#include "Literal_Table.h"
using namespace std;
#ifndef IS_FOUND_FUNCTION_H_DEF
#define IS_FOUND_FUNCTION_H_DEF
bool IS_Found_In_Literal_Table(string current_value,vector <Literal_Table> &LITERAL_Table);
string _Get_Label_LOC(string Label,vector <Symbol_Table> &Table);
string _Get_Literal_In_Literal_Table(string Label,vector <Literal_Table> &LITERAL_Table);

#endif // IS_FOUND_FUNCTION_H_DEF
