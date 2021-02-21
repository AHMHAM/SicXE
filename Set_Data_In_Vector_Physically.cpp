#include "Set_Data_In_Vector_Physically.h"

void _Store_DATA_In_Vector(string Current_Str,int location,vector<Symbol_Table> &Table,
                          vector<string> &Labels,vector<string> &Instruction,
                          int &current_location,string &Prog_Loc_Counter)
{
    string check=_Instruction_Found_Get_INST(Current_Str);

    if(check==NOT_FOUND) //Not Instruction
    {
         if(location==0) //we must store location if it at 0 like label for jump
         {
             if(Current_Str!="LTORG") //ltorg handler
             {
                 Table.push_back(Symbol_Table());
                 Table[current_location].Label=Current_Str;
                 Table[current_location].Label_Location=Prog_Loc_Counter;
                 current_location++;
             }
         }

         else if ((location==1||location==2)&&_Check_If_DECLERATION(Current_Str)!=RESB&&_Check_If_DECLERATION(Current_Str)!=RESW)
         {
                Labels.push_back(Current_Str);
         }

         else if((location==1||location==2)&&(_Check_If_DECLERATION(Current_Str)==RESB||_Check_If_DECLERATION(Current_Str)==RESW))
         {
            Labels.push_back(RESB);
            Instruction.push_back("-1");
         }
    }
    else
        {
            Instruction.push_back(Current_Str);
        }
}
