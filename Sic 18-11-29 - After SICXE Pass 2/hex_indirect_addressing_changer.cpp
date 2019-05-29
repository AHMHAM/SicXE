#include "hex_indirect_addressing_changer.h"

string _Hex_To_Binary_As_STR(string Hex_Number_Will_Be_CONV);
int _Binary_To_Int(string Binary_Number_Will_Be_CONV);

string _Hex_Indirect_CHANGER(string current_hex)
{
    string Hex_Into_Binary=_Hex_To_Binary_As_STR(current_hex);
    Hex_Into_Binary[0]='1';   // change most significant bit to 1
    reverse(Hex_Into_Binary.begin(),Hex_Into_Binary.end()); //Reverse String Because We read Hex From Right To Left like 003c c when read array have weight 3 in hex have 0
   int Int_Value = _Binary_To_Int(Hex_Into_Binary);
   return _Int_To_Hex_STR(Int_Value,current_hex.size());
}
string _Hex_To_Binary_As_STR(string Hex_Number_Will_Be_CONV)
{
    string String="";
    int Reminder_From_DIV=0;
    reverse(Hex_Number_Will_Be_CONV.begin(),Hex_Number_Will_Be_CONV.end());
    int Number_Will_Be_CONV=_Hex_String_To_INT(Hex_Number_Will_Be_CONV);
    for(int i=15;i>=0;i--) // 15 because maximum number we will convert it 16 bit from 0 -> 15
    {
        if(Number_Will_Be_CONV>=pow(2,i))      //If  We must Find Power<=Sum
        {
        Reminder_From_DIV = Number_Will_Be_CONV/pow(2,i);
        String+=(Reminder_From_DIV+'0');
       Number_Will_Be_CONV-=Reminder_From_DIV * pow(2,i);
        }
        else
            String+='0';
    }
    return String;

}
int _Binary_To_Int(string Binary_Number_Will_Be_CONV)
{
    int SUM=0;
    for(int i=0;i<Binary_Number_Will_Be_CONV.size();i++){
        SUM+=(Binary_Number_Will_Be_CONV[i]-'0')*pow(2,i);
    }

  return SUM;
}
