#include "Chek_if_Dec.H"
const string Dec [4]={"WORD","BYTE","RESW","RESB"};
string _Check_If_DECLERATION(string current_string)
{
    for(int i=0;i<4;i++)
    if(current_string==Dec[2])
        return RESW;
    else if(current_string==Dec[3])
        return RESB;
    else if(current_string==Dec[1])
        return BYTE;
    else if(current_string==Dec[0])
        return WORD;
    return NOT_FOUND;
}


