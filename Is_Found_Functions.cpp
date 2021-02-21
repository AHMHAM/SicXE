#include "Is_Found_Functions.h"

bool IS_Found_In_Literal_Table(string current_value,vector <Literal_Table> &LITERAL_Table)
{
   for(int i=0;i<LITERAL_Table.size();i++)
   {
     if(LITERAL_Table[i].Value==current_value)
        return true;
   }
   return false;
}
string _Get_Literal_In_Literal_Table(string Label,vector <Literal_Table> &LITERAL_Table)
{
    for(int i=0;i<LITERAL_Table.size();i++)
    {
        if(Label==LITERAL_Table[i].Value)
            return LITERAL_Table[i].Address;
    }
    return NOT_FOUND;
}
string _Get_Label_LOC(string Label,vector <struct Symbol_Table> &Table)
{
    for(int i=0;i<Table.size();i++)
    {
        if(Label==Table[i].Label)
            return Table[i].Label_Location;
    }
    return NOT_FOUND;
}
