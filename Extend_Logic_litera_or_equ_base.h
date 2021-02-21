#include <string>
#include<vector>
#include "Literal_Adder_Loc_Counter.h"
#include"instruction_find.h"
#include "Is_Found_Functions.h"
#include "Expression_Calculator.h"

#include "Symbol_Table.h"
#include "Literal_Table.h"
using namespace std;
#ifndef EXTEND_LOGIC_LITERAL_OR_EQU_BASE_H_DEF
#define EXTEND_LOGIC_LITERAL_OR_EQU_BASE_H_DEF
void Extended_Logic_For_Equ_Or_Base_Literal(string (&Current_Line_Without_Spac)[4],
                                            vector<string> &Labels,
                                            vector<string> &Prog_Loc_Counter_Array,
                                            bool &not_EQU,vector<string> &Instruction,
                                            vector <Symbol_Table> &Table,
                                            vector <Literal_Table> &LITERAL_Table,
                                            bool &End_Rive,string &Prog_Loc_Counter,
                                            int &current_location);
#endif // EXTEND_LOGIC_LITERAL_OR_EQU_BASE_H_DEF
