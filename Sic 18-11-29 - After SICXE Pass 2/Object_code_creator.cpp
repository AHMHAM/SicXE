#include "Object_code_creator.h"
string removing_leading_zeros(string str)
{
    string temp="";
    for(int i=str.size()-1;i>=str.size()-4;i--)
    {
        temp+=str[i];
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
string OBJECT_CODE_Create(string instruction ,string label ,string next_location ,
                          vector <Symbol_Table> &Table,vector <Literal_Table> &LITERAL_Table)
{
    string instruction_format=_Instruction_Get_FORMAT(instruction);
    if(instruction_format!=NOT_FOUND)
    {
        if(instruction_format==FORMAT_ONE)
          return _Instruction_Found_Get_INST(instruction);

        else if(instruction_format==FORMAT_TWO)
        {
           string returned_object_code="";
            if(label.size()==1) //one register
            {
              returned_object_code=_Instruction_Found_Get_INST(instruction);
              returned_object_code+=register_value(label[0]);
              returned_object_code+="0";
            }
            else
            {
              returned_object_code=_Instruction_Found_Get_INST(instruction);
              returned_object_code+=register_value(label[0]);
              returned_object_code+=register_value(label[1]);
            }
            return returned_object_code;
        }

        else if(instruction_format==FORMAT_THREE)
        {
            string returned_object_code="";
            string str=_Instruction_Found_Get_INST(instruction);
            returned_object_code+=str[0];
            string temp="";
            temp+=str[1];
            str=_Hex_To_Binary_As_STR(temp);
            str=removing_leading_zeros(str);
            string second_num="";
            second_num+=str[0];
            second_num+=str[1];
            second_num+=Flags_n_i(label);
            reverse(second_num.begin(),second_num.end());
            int second_value=_Binary_To_Int(second_num);
            returned_object_code+=_Int_To_Hex_STR(second_value,1);
            if(label[0]=='#'||label[0]=='@'||label[0]=='=')
            {
              label.erase(0, label.find_first_not_of(label[0]));
            }
            second_num="";
            string hex_disp="";

              if(is_number(label))
              {
                  second_num+="0";
                  second_num+="0";
                  hex_disp=_Int_To_Hex_STR(_Str_To_INT(label),3);
              }
            else
            {
                hex_disp=_String_Hex_DEC_X(_Get_Label_LOC(label,Table),next_location);
                hex_disp=String_Decrease_SIZE(hex_disp,'0');
                if(hex_disp.size()==4)
                   hex_disp.erase(0, 1);
                second_num+=Flags_x_b_p(label,next_location,instruction_format,hex_disp);
            }
            second_num+="0"; // e=0 because format 3
            reverse(second_num.begin(),second_num.end());
            second_value=_Binary_To_Int(second_num);
            returned_object_code+=_Int_To_Hex_STR(second_value,1);
            hex_disp=String_To_Opcode_Change_Size_TO_X(hex_disp,3,'0');
            returned_object_code+=hex_disp;
            return returned_object_code;
        }

        else if(instruction_format==FORMAT_FOUR)
        {
            string returned_object_code="";
            string str=_Instruction_Found_Get_INST(instruction);
            returned_object_code+=str[0];
            string temp="";
            temp+=str[1];
            str=_Hex_To_Binary_As_STR(temp);
            str=removing_leading_zeros(str);
            string second_num="";
            second_num+=str[0];
            second_num+=str[1];
            second_num+=Flags_n_i(label);
            int second_value=_Binary_To_Int(second_num);
            returned_object_code+=_Int_To_Hex_STR(second_value,1);
            second_num="";
            second_num+=Flags_x_b_p(label,next_location,instruction_format,"");
            second_num+="1"; // e=1 because format 4
            reverse(second_num.begin(),second_num.end());
            second_value=_Binary_To_Int(second_num);
            returned_object_code+=_Int_To_Hex_STR(second_value,1);
            returned_object_code+=String_To_Opcode_Change_Size_TO_X(_Get_Label_LOC(label,Table),5,'0');
            return returned_object_code;
        }

    }
}
