#include "Literal_Adder_Loc_Counter.h"

void literal_add(vector<string> &Labels, vector<string> &Instruction,
                 vector<string> &Prog_Loc_Counter_Array,
                 vector <Literal_Table> &LITERAL_Table,bool &End_Rive,
                 string &Prog_Loc_Counter)
{
    string temp;
    for(int i=0;i<LITERAL_Table.size();i++)
    {
        if(LITERAL_Table[i].Takken==false)
        {
            temp=LITERAL_Table[i].Value;
            temp.insert(0,"=");
            Labels.push_back("*");
            Instruction.push_back(temp);
            if(End_Rive==true) //end prog
            {
                LITERAL_Table[i].Address=Prog_Loc_Counter_Array[Prog_Loc_Counter_Array.size()-1];
                Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,LITERAL_Table[i].LENGTH,HEX_ONE);
                Prog_Loc_Counter_Array.push_back(Prog_Loc_Counter);
            }
            else
            {
                Prog_Loc_Counter_Array.push_back(Prog_Loc_Counter);
                Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,LITERAL_Table[i].LENGTH,HEX_ONE);
                LITERAL_Table[i].Address=Prog_Loc_Counter_Array[Prog_Loc_Counter_Array.size()-1];
            }
            LITERAL_Table[i].Takken=true;
        }
    }
}
