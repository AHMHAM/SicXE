#include <string>
#include <vector>
#include "currentline_divide_strings.h"
#include "Input_Data_In_Vector_Logic_Only.h"
#include "Extend_Logic_litera_or_equ_base.h"

#include "Symbol_Table.h"
#include "Literal_Table.h"
using namespace std;
#ifndef PASS_ONE_H_DEF
#define PASS_ONE_H_DEF
void PASS_ONE(bool &Start_Prog_Flag,string &Prog_Name,string &Prog_Loc_Counter,
              string &startposition,string Current_Line,vector<string> &Instruction,
              vector <Literal_Table> &LITERAL_Table,vector <Symbol_Table> &Table,
              vector<string> &Labels,int &current_location,int &LITERAL_Table_location,
              vector<string> &Prog_Loc_Counter_Array,bool &End_Rive);
#endif // PASS_ONE_H_DEF
