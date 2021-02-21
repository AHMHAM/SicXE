#include <string>
#include <vector>
#include "Set_Data_In_Vector_Physically.h"
#include "Chek_if_Dec.H"
#include "String _To_Opcode_Fit_8.h"
#include "Is_Found_Functions.h"

#include "Symbol_Table.h"
#include "Literal_Table.h"
using namespace std;
#ifndef INPUT_DATA_IN_VECTOR_LOGIC_ONLY_H_DEF
#define INPUT_DATA_IN_VECTOR_LOGIC_ONLY_H_DEF
void Set_Data_Into_Vecotors(string *Current_Line_Without_Spac,vector<string> &Instruction,
                            vector <Literal_Table> &LITERAL_Table,vector<Symbol_Table> &Table,
                            vector<string> &Labels,int &current_location,
                            int &LITERAL_Table_location,string &Prog_Loc_Counter);
#endif // INPUT_DATA_IN_VECTOR_LOGIC_ONLY_H_DEF
