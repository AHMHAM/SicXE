#include<string>
#include "instruction_find.h"
#include "formate_two_register_values.h"
#include "hex_indirect_addressing_changer.h"
#include "Object_code_flags.h"
#include "Is_Found_Functions.h"

using namespace std;
#ifndef OBJECT_CODE_CREATOR_H_DEF
#define OBJECT_CODE_CREATOR_H_DEF
string OBJECT_CODE_Create(string instruction ,string label ,string next_location ,vector <Symbol_Table> &Table,vector <Literal_Table> &LITERAL_Table);
#endif // OBJECT_CODE_CREATOR_H_DEF
