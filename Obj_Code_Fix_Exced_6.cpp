#include "Obj_Code_Fix_Exced_6.h"
void Object_Code_Fix_Exced_6(vector<string> &Current_Obj_Code,string Exced_Obj_Code)
{
    string Another="";
    for(int i=0;i<Exced_Obj_Code.size();i++)
    {
        Another+=Exced_Obj_Code.substr(i,1);
        if(Another.size()==6)
         {
            Current_Obj_Code.push_back(Another);
            Another="";
         }
    }
    if(Another!="")
    Current_Obj_Code.push_back(Another);
}
