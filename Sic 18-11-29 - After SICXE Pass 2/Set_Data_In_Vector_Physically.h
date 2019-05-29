#include <string>
#include <vector>
#include "Chek_if_Dec.H"
#include"instruction_find.h"

#include "Symbol_Table.h"
using namespace std;
#ifndef SET_DATA_IN_VECTOR_PHYSICALLY_H_DEF
#define SET_DATA_IN_VECTOR_PHYSICALLY_H_DEF
void _Store_DATA_In_Vector(string Current_Str,int location,vector<Symbol_Table> &Table,
                          vector<string> &Labels,vector<string> &Instruction,
                          int &current_location,string &Prog_Loc_Counter);
#endif // SET_DATA_IN_VECTOR_PHYSICALLY_H_DEF
