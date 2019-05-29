#include <string>
#include <vector>
#include"hex_inc_dec.h"
#include"instruction_find.h"

#include "Literal_Table.h"
using namespace std;
#ifndef LITERAL_ADDER_LOC_COUNTER_H_DEF
#define LITERAL_ADDER_LOC_COUNTER_H_DEF
void literal_add(vector<string> &Labels, vector<string> &Instruction,
                 vector<string> &Prog_Loc_Counter_Array,
                 vector <Literal_Table> &LITERAL_Table,bool &End_Rive,
                 string &Prog_Loc_Counter);
#endif // LITERAL_ADDER_LOC_COUNTER_H_DEF
