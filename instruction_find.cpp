#include"instruction_find.h"
//n = 1, i = 1
const string SICXE_Format3_Instruction_Set_NAME [42]={"ADD","ADDF","AND","COMP","COMPF","DIV","DIVF","J" ,"JEQ","JGT","JLT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","OR","RD","RSUB","SSK","STA","STB","STCH","STF","STL","STI","STS","STSW","STT","STX","SUB","SUBF","TD","TIX","WD"};
const string SICXE_Format3_Instruction_Set_OP  [42]={"18" ,"58"  ,"40" ,"28"  ,"88"   ,"24" ,"64"  ,"3C","30" ,"34" ,"38" ,"48"  ,"00" ,"68" ,"50"  ,"70" ,"08" ,"6C" ,"74" ,"04" ,"D0" ,"20" ,"60"  ,"44","D8","4C"  ,"EC" ,"0C" ,"78" ,"54"  ,"80" ,"14" ,"D4" ,"7C" ,"E8"  ,"84" ,"10" ,"1C" ,"5C"  ,"E0","2C" ,"DC"};

const string SICXE_Format2_Instruction_Set_NAME [11]={"ADDR","CLEAR","COMPR","DIVR","MULR","RMO","SHIFTL","SHIFTR","SUBR","SVC","TIXR"};
const string SICXE_Format2_Instruction_Set_OP  [11]={"90"  ,"B4"   ,"A0"   ,"9C"  ,"98"  ,"AC" ,"A4"    ,"A8"    ,"94"  ,"B0" ,"B8"};

const string SICXE_Format1_Instruction_Set_NAME [6]={"FIX","FLOAT","HIO","NORM","SIO","TIO"};
const string SICXE_Format1_Instruction_Set_OP  [6]={"C4" ,"C0"   ,"F4" ,"C8"  ,"F0" ,"F8"};
const string SICXE_EQU="";
string _Instruction_Found_Get_INST(string current_string)
{
    for(int i=0;i<42;i++)
    if(current_string=="+"+SICXE_Format3_Instruction_Set_NAME[i])
        return SICXE_Format3_Instruction_Set_OP[i];

    for(int i=0;i<42;i++)
    if(current_string==SICXE_Format3_Instruction_Set_NAME[i])
        return SICXE_Format3_Instruction_Set_OP[i];
    for(int i=0;i<11;i++)
    if(current_string==SICXE_Format2_Instruction_Set_NAME[i])
        return SICXE_Format2_Instruction_Set_OP[i];
    for(int i=0;i<6;i++)
    if(current_string==SICXE_Format1_Instruction_Set_NAME[i])
        return SICXE_Format1_Instruction_Set_OP[i];
    return NOT_FOUND;
}

string _Instruction_Get_FORMAT(string current_string)
{
    for(int i=0;i<42;i++)
    if(current_string=="+"+SICXE_Format3_Instruction_Set_NAME[i])
        return FORMAT_FOUR;

    for(int i=0;i<42;i++)
    if(current_string==SICXE_Format3_Instruction_Set_NAME[i])
        return FORMAT_THREE;
    for(int i=0;i<11;i++)
    if(current_string==SICXE_Format2_Instruction_Set_NAME[i])
        return FORMAT_TWO;
    for(int i=0;i<6;i++)
    if(current_string==SICXE_Format1_Instruction_Set_NAME[i])
        return FORMAT_ONE;

    return NOT_FOUND;
}

bool _Instruction_Found_Get_Location_Count_INC(string &Prog_Loc_Counter,string (&Current_Line_Without_Spac)[4],int Instruction_Loc)
{
   if(_Check_If_DECLERATION(Current_Line_Without_Spac[1])==RESB)
   {
        Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,HEX_ONE,Current_Line_Without_Spac[2]/*This Offset After resb*/);
        return true;
   }
   else if(_Check_If_DECLERATION(Current_Line_Without_Spac[1])==RESW)
   {
        Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,HEX_THREE,Current_Line_Without_Spac[2]/*This Offset After resw*/);
        return true;
   }
   else if(_Check_If_DECLERATION(Current_Line_Without_Spac[1])==BYTE)
   {
       int str_size=Current_Line_Without_Spac[2].size()-3;
       if(Current_Line_Without_Spac[2][0]=='C'||Current_Line_Without_Spac[2][0]=='c')
        Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,(String_To_Opcode_Change_Size_TO_X(to_string(str_size),4,'0'))/*-3 is c'' like c'eof'*/,HEX_ONE/*This For Normal Byte Inc By 1*/);

     else if(Current_Line_Without_Spac[2][0]=='X'||Current_Line_Without_Spac[2][0]=='x')
     {
         int inc_size=ceil((str_size*1.0)/2.0);
        Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,String_To_Opcode_Change_Size_TO_X(to_string(inc_size),4,'0') /*-3 is x'' like c'f1'* we will inc by one*/,HEX_ONE/*This For Normal Byte Inc By 1*/);
     }
     else
        Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,String_To_Opcode_Change_Size_TO_X(Current_Line_Without_Spac[2],4,'0')/*to fit number in 4 digit and inc*/,HEX_ONE/*This For Normal Byte Inc By 1*/);
        return true;
   }
   else if(_Check_If_DECLERATION(Current_Line_Without_Spac[1])==WORD)
   {
        Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,HEX_THREE,HEX_ONE/*This For Normal Byte Inc By 1*/);
        return true;
   }
    else if(Current_Line_Without_Spac[Instruction_Loc][0]=='+')
      {
        Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,HEX_FOUR,HEX_ONE /* inc by 4hex offset 1*/);
              return true;
      }
    else
        {
            for(int i=0;i<42;i++)
                if(Current_Line_Without_Spac[Instruction_Loc]== SICXE_Format3_Instruction_Set_NAME[i])
            {
                Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,HEX_THREE,HEX_ONE/* inc by 3hex offset 1*/);
                return true;
            }
            for(int i=0;i<11;i++)
            if(Current_Line_Without_Spac[Instruction_Loc]==SICXE_Format2_Instruction_Set_NAME[i])
            {
                Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,HEX_TWO,HEX_ONE/* inc by 2hex offset 1*/);
                return true;
            }
            for(int i=0;i<6;i++)
            if(Current_Line_Without_Spac[Instruction_Loc]==SICXE_Format1_Instruction_Set_NAME[i])
            {
                Prog_Loc_Counter=_String_Hex_INC_X(Prog_Loc_Counter,HEX_ONE,HEX_ONE/* inc by 1hex offset 1*/);
                return true;
            }
            return false;
        }
}
