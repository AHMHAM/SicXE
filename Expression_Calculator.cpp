#include "Expression_Calculator.h"
string expression_calc_disp(string current_str,vector <Symbol_Table> &Table)
{
    int sign_count=0;
    string current_label="";
    vector<string> labels_must_calc_disp;
    for(int i=0;i<current_str.size();i++)
    {
        if((current_str[i]=='-')||(current_str[i]=='+')||(current_str[i]=='*')||(current_str[i]=='/'))
        {
            labels_must_calc_disp.push_back(current_label);
            sign_count++;
            current_label="";
            labels_must_calc_disp.push_back(string(1, current_str[i]));
        }
        else
        current_label+=current_str[i];
    }
     if(current_label!="")
        labels_must_calc_disp.push_back(current_label);

    if((labels_must_calc_disp.size()-sign_count)==sign_count+1)
    {
        for(int i=1;i<labels_must_calc_disp.size();i+=2)
        {
            if(labels_must_calc_disp[i]=="-")
            {
                labels_must_calc_disp[i+1] = _String_Hex_DEC_X(_Get_Label_LOC(labels_must_calc_disp[i-1],Table),_Get_Label_LOC(labels_must_calc_disp[i+1],Table));
            }
        }
        return labels_must_calc_disp[labels_must_calc_disp.size()-1];
    }

    else if(labels_must_calc_disp.size()==1)
    {
        return _Get_Label_LOC(labels_must_calc_disp[0],Table);
    }
}
