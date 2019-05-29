#include "pass1.h"
string Current_Line_Without_Spac[4]; //this array store line without spacing like h1w1a start 1010 put it in pos 0 h1w1a pos 1 start (4 because we have label and inst and label and x if u have) mustn't have 4 string .....
bool not_EQU=false;
void PASS_ONE(bool &Start_Prog_Flag,string &Prog_Name,string &Prog_Loc_Counter,
              string &startposition,string Current_Line,vector<string> &Instruction,
              vector <Literal_Table> &LITERAL_Table,vector <Symbol_Table> &Table,
              vector<string> &Labels,int &current_location,int &LITERAL_Table_location,
              vector<string> &Prog_Loc_Counter_Array,bool &End_Rive)
{
   _Current_Line_Divide_Strings_BYREF(Current_Line,Current_Line_Without_Spac);

       // here we will check if we start program or not if start initialize variable
       if(Current_Line_Without_Spac[1]=="START")
       {
        Start_Prog_Flag=true;
        Prog_Name= Current_Line_Without_Spac[0];
        Prog_Loc_Counter=Current_Line_Without_Spac[2];
        startposition=Current_Line_Without_Spac[2];
       }

       // if we in code
       else if(Start_Prog_Flag==true&&Current_Line_Without_Spac[1]!="START")
       {
         Set_Data_Into_Vecotors(Current_Line_Without_Spac,Instruction,LITERAL_Table,
                                Table,Labels,current_location,LITERAL_Table_location,
                                Prog_Loc_Counter);

         Extended_Logic_For_Equ_Or_Base_Literal(Current_Line_Without_Spac,Labels,
                                                Prog_Loc_Counter_Array,not_EQU,
                                                Instruction,Table,LITERAL_Table,
                                                End_Rive,Prog_Loc_Counter,
                                                current_location);
       }
}
