#include "currentline_divide_strings.h"
void _Current_Line_Divide_Strings_CLEAR(string *current_line_divided)
{
    for(int i=0;i<4;i++)
        current_line_divided[i]="";
}
void _Current_Line_Divide_Strings_BYREF(string current_line,string *current_line_divided)
{
    _Current_Line_Divide_Strings_CLEAR(current_line_divided);
    int k=0,j;  //k is for escape spaces in  current line string like hw1b start 0030 k must make hw1bstart0030
    for(int i=0;i<4;i++)
    {
        for(j=k;current_line[j]!=' '&&j<current_line.size();j++)
        {
            if(current_line[j]!=',')
            current_line_divided[i]+=current_line[j];
        }
        k=j+1;
    }
}
