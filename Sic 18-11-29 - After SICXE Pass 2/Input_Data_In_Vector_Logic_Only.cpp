#include "Input_Data_In_Vector_Logic_Only.h"

void Set_Data_Into_Vecotors(string *Current_Line_Without_Spac,vector<string> &Instruction,
                            vector <Literal_Table> &LITERAL_Table,
                            vector<Symbol_Table> &Table,vector<string> &Labels,
                            int &current_location,int &LITERAL_Table_location,
                            string &Prog_Loc_Counter)
{
    for(int i=0;i<4;i++)
    {
        // BASE handler
        if(Current_Line_Without_Spac[0]=="BASE")
        {
          //  Base_Labels.push_back(Current_Line_Without_Spac[1]);
            break;
        }
        if(Current_Line_Without_Spac[1]=="BASE")
        {
          //  Base_Labels.push_back(Current_Line_Without_Spac[2]);
            break;
        }

        if(Current_Line_Without_Spac[1]=="EQU")
            break; //we will store equ manually

        if(Current_Line_Without_Spac[i]!="")
            _Store_DATA_In_Vector(Current_Line_Without_Spac[i],i,Table,Labels,
                                  Instruction,current_location,Prog_Loc_Counter);


        if(_Check_If_DECLERATION(Current_Line_Without_Spac[i])!=NOT_FOUND)
        {
            string check=_Check_If_DECLERATION(Current_Line_Without_Spac[i]);

            if(check!=RESB&&check!=RESW)
            {
               Instruction.push_back(String_To_Opcode(Current_Line_Without_Spac[2]));
            }

            i++;
        }

        if(Current_Line_Without_Spac[i][0]=='=')
        {
            Current_Line_Without_Spac[i].erase(0,1);

            //if condition found mean we have already this literal ( for non duplicated )
            if(IS_Found_In_Literal_Table(Current_Line_Without_Spac[i],LITERAL_Table)==false)
            {
                int str_size=Current_Line_Without_Spac[i].size()-3;
                LITERAL_Table.push_back(Literal_Table());
                LITERAL_Table[LITERAL_Table_location].Value=Current_Line_Without_Spac[i];

                LITERAL_Table[LITERAL_Table_location].op_code_value=String_To_Opcode(Current_Line_Without_Spac[i]); // op code handeler value

                if((Current_Line_Without_Spac[i][0]=='x')||(Current_Line_Without_Spac[i][0]=='X'))
                {
                    int inc_size=ceil((str_size*1.0)/2.0);
                    LITERAL_Table[LITERAL_Table_location].LENGTH=String_To_Opcode_Change_Size_TO_X(to_string(inc_size),4,'0');
                }
                else
                LITERAL_Table[LITERAL_Table_location].LENGTH=String_To_Opcode_Change_Size_TO_X(to_string(str_size),4,'0');
                LITERAL_Table_location++;
            }
        }
    }
}
