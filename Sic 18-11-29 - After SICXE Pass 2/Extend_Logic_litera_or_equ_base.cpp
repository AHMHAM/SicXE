#include "Extend_Logic_litera_or_equ_base.h"
void Extended_Logic_For_Equ_Or_Base_Literal(string (&Current_Line_Without_Spac)[4],
                                            vector<string> &Labels,
                                            vector<string> &Prog_Loc_Counter_Array,
                                            bool &not_EQU,vector<string> &Instruction,
                                            vector <Symbol_Table> &Table,
                                            vector <Literal_Table> &LITERAL_Table,
                                            bool &End_Rive,string &Prog_Loc_Counter,
                                            int &current_location)
{
    if(Current_Line_Without_Spac[1]=="")
    Labels.push_back("");
    if((Current_Line_Without_Spac[0]=="BASE")||(Current_Line_Without_Spac[1]=="BASE"))
    {

    }

   else if(Current_Line_Without_Spac[0]=="LTORG")
    {
       literal_add(Labels,Instruction,Prog_Loc_Counter_Array,LITERAL_Table,End_Rive,Prog_Loc_Counter);
    }
    else
    {
         Prog_Loc_Counter_Array.push_back(Prog_Loc_Counter);
         if(_Instruction_Found_Get_INST(Current_Line_Without_Spac[0])!=NOT_FOUND)
         {
           not_EQU=_Instruction_Found_Get_Location_Count_INC(Prog_Loc_Counter,Current_Line_Without_Spac,0);
         }

         else if(_Instruction_Found_Get_INST(Current_Line_Without_Spac[1])!=NOT_FOUND)
         {
           not_EQU=_Instruction_Found_Get_Location_Count_INC(Prog_Loc_Counter,Current_Line_Without_Spac,1);
         }

         else
         {
              not_EQU=_Instruction_Found_Get_Location_Count_INC(Prog_Loc_Counter,Current_Line_Without_Spac,1);
              if((not_EQU==false)&&_Get_Label_LOC(Current_Line_Without_Spac[1],Table)==NOT_FOUND) //this EQUATE inst
              {
                Labels.push_back(Current_Line_Without_Spac[0]);
                Instruction.push_back(Current_Line_Without_Spac[1]);
                if(Current_Line_Without_Spac[2]=="*")
                Prog_Loc_Counter_Array[Prog_Loc_Counter_Array.size()-1]=Prog_Loc_Counter;

                else if(is_number(Current_Line_Without_Spac[2]))
                {
                    reverse(Current_Line_Without_Spac[2].begin(),Current_Line_Without_Spac[2].end());
                    int int_value=_Str_To_INT(Current_Line_Without_Spac[2]);
                    string Hex_Num_After_CONV=_Int_To_Hex_STR(int_value,4);
                    Prog_Loc_Counter_Array[Prog_Loc_Counter_Array.size()-1]=Hex_Num_After_CONV;
                }
                else
                   Prog_Loc_Counter_Array[Prog_Loc_Counter_Array.size()-1]=expression_calc_disp(Current_Line_Without_Spac[2],Table);

                    Table.push_back(Symbol_Table());
                    Table[current_location].Label=Current_Line_Without_Spac[0];
                    Table[current_location].Label_Location=Prog_Loc_Counter_Array[Prog_Loc_Counter_Array.size()-1];
                    current_location++;
              }

         }
    }
}
