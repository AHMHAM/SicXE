#include "String _To_Opcode_Fit_8.h"
string String_To_Opcode(string String)
{
    string to_string;
    int temp;
    if(String[0]=='X'||String[0]=='x')
    {
        for(int i=2;i<String.size()-1;i++)
            to_string+=String[i];
        return to_string;
    }
      else if(String[0]=='C'||String[0]=='c')
    {
        for(int i=2;i<String.size()-1;i++)
        {
            temp=String[i];
            to_string+=_Int_To_Hex_STR(temp,2);
        }
        return to_string;
    }
    reverse(String.begin(),String.end());
    temp=_Str_To_INT(String);
    to_string=_Int_To_Hex_STR(temp,String.size());
    return to_string;
}
string String_To_Opcode_Change_Size_TO_X(string Current_Op_code,int x,char place_holder)
{
    string fitted_string="";
    int zeros_size=x-Current_Op_code.size();
    for(int i=0;i<zeros_size;i++) // because we will fit string in 6 digits;
    {
        fitted_string+=place_holder;
    }
    return fitted_string+Current_Op_code;

}
string String_Decrease_SIZE(string Current_strig,char Remove_place_holder)
{
    string fitted_string="";
    for(int i=0;i<Current_strig.size();i++) // because we will fit string in 6 digits;
    {
        if(Current_strig[i]!=Remove_place_holder)
        fitted_string+=Current_strig[i];
    }
    return fitted_string;

}

