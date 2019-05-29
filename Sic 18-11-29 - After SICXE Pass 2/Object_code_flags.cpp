#include "Object_code_flags.h"
string Flags_n_i(string label)
{
    string n_i="";
   if(label[0]=='#')
   {
       n_i+="0";
       n_i+="1";
       return n_i;
   }
   else if(label[0]=='@')
   {
       n_i+="1";
       n_i+="0";
       return n_i;
   }
   else
   {
       n_i+="1";
       n_i+="1";
       return n_i;
   }
}

string Flags_x_b_p(string label,string next_location,string format,string hex_disp)
{
  string x_b_p="";
  if(label[label.size()-1]=='x'||label[label.size()-1]=='X')
    x_b_p+="1";
  else
    x_b_p+="0";

    if(format==FORMAT_FOUR)
    {
        x_b_p+="0";
        x_b_p+="0";
        return x_b_p;
    }
  else
  {
      reverse(hex_disp.begin(),hex_disp.end());
      int disp=_Hex_String_To_INT(hex_disp);
      reverse(hex_disp.begin(),hex_disp.end());
      if(disp<=2048)
      {
        x_b_p+="0";
        x_b_p+="1";
        return x_b_p;
      }
      else if(disp>2048&&disp<=4096)
      {
        x_b_p+="1";
        x_b_p+="0";
        return x_b_p;
      }
  }
}
