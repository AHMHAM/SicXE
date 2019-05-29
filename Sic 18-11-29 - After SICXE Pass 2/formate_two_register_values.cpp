#include "formate_two_register_values.h"
const char Register_Names [14]={'A','X','L','B','S','T','F','a','x','l','b','s','t','f'};
const string Register_Values  [14]={"0" ,"1","2","3","4","5","6","0","1","2","3" ,"4","5","6"};

string register_value(char reg)
{
    for(int i=0;i<14;i++)
    if(reg==Register_Names[i])
        return Register_Values[i];
    return "Not Found";
}
