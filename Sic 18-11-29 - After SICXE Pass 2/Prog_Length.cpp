#include "Prog_Length.h"
using namespace std;
void Prog_Length_Calc(vector<string> &Current_Obj_Code,vector<string> &Current_Loc_Counter,vector<string> &Current_Length)
{for(int i=0;i<Current_Obj_Code.size();i++)
cout<<i<<"    "<<Current_Obj_Code[i]<<endl;
    int i=0,last=0,sum_bits=0,j=0;
           for(i=0;last<Current_Obj_Code.size();i++)
           {
                for( j=last;(sum_bits+Current_Obj_Code[j].size())<=60&&Current_Obj_Code[j]!="-1"&&j<=Current_Obj_Code.size();j++)
                    {
                        sum_bits+=Current_Obj_Code[j].size();
                    }
                if(Current_Obj_Code[j]=="-1")
                j++;
                cout<<Current_Loc_Counter[j]<<"    "<<Current_Loc_Counter[last]<<endl;
              Current_Length.push_back(String_Decrease_SIZE(_String_Hex_DEC_X(Current_Loc_Counter[j],Current_Loc_Counter[last]),'0'));
                sum_bits=0;
                last=j;
           }
}
