#include<string>
#include<vector>
#include "Object_code_creator.h"
#include "Symbol_Table.h"
#include "Literal_Table.h"

using namespace std;
#ifndef PASS_TWO_H_DEF
#define PASS_TWO_H_DEF
void PASS_TWO(vector<string> &Labels,vector<string> &Instruction,
              vector<string> &Prog_Loc_Counter_Array,vector <Symbol_Table> &Table,
              vector<string> &Ob_Code_For_Hte,vector <Literal_Table> &LITERAL_Table);
#endif // PASS_TWO_H_DEF
