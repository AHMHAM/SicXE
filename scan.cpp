#include"scan.h"
using namespace std;
string Prog_Name,Prog_Loc_Counter;
vector<string> Labels;
vector<string> Instruction;
vector<string> Prog_Loc_Counter_Array;
vector<string> Ob_Code_For_Hte;
int line_counter=0; //number of line in program
string startposition;
int current_location=0;
int LITERAL_Table_location=0;
bool End_Rive=false;
bool IsFile_Found(string file_path);
void _Store_DATA(string Current_Str );
void Pass_ONE(string File_Path);
void test();
void test2();
void Pass_TWO(string File_Path);

vector <Symbol_Table> Table;

vector <Literal_Table> LITERAL_Table;

bool IsFile_Found(string file_path)
{
        ifstream File(file_path.c_str());
        return (bool)File;
}

///Pass One
void Pass_ONE(string File_Path)
{
    if(IsFile_Found(File_Path))
    {
       bool Start_Prog_Flag;
       ifstream File_Read;
       string Current_Line="";
       File_Read.open(File_Path.c_str());

        while (getline(File_Read, Current_Line)) // Here We Take Line In File and put it in Current_Line
        {
           PASS_ONE(Start_Prog_Flag,Prog_Name,Prog_Loc_Counter,startposition,Current_Line,Instruction,
                    LITERAL_Table,Table,Labels,current_location,LITERAL_Table_location,
                    Prog_Loc_Counter_Array,End_Rive);
           line_counter++;
        }
        if(LITERAL_Table.size()>0)
        {
            End_Rive=true;
            literal_add(Labels,Instruction,Prog_Loc_Counter_Array,LITERAL_Table,End_Rive,Prog_Loc_Counter);
        }
    }
}
/////Pass Two
void Pass_TWO(string File_Path)
{
    PASS_TWO(Labels,Instruction,Prog_Loc_Counter_Array,Table,Ob_Code_For_Hte,LITERAL_Table);
//    if(IsFile_Found(File_Path))
//    {
//        int current_Ob_For_Hte=0;// because we set -1 if it resb or resw
//       ofstream File_Write;
//       string Current_Opcode="";
//       File_Write.open(File_Path.c_str());
//       ///Symbol Table
//       File_Write<<"                                 SYMBOL TABLE"<<endl;
//       File_Write<<"-------------------------------------------------------------------------------------------"<<endl;
//       File_Write<<"			   ------------------------"<<endl;
//
//       for(int i=0;i<Table.size()&&Table[i].Label!="END";i++)
//       {
//        File_Write<<"			  |"<<Table[i].Label<<"               "<<Table[i].Label_Location<<endl;
//        if(i<Table.size()-2)
//        File_Write<<"                          |------------------------"<<endl;
//       }
//
//
//       ///OP Code & Location Counter
//       File_Write<<"                           ------------------------"<<endl;
//       File_Write<<"==========================================================================================="<<endl;
//       File_Write<<"                          OP Code & Location Counter"<<endl;
//       File_Write<<"-------------------------------------------------------------------------------------------"<<endl;
//       File_Write<<"			   ------------------------"<<endl;
//
//        for(int i=0;i<Labels.size()-1;i++) // 34an ma5od4 ma3aya al location bata3 end
//        {
//            File_Write<<"			  |"<<Prog_Loc_Counter_Array[i];
//           if(Labels[i]=="") //RSUB OBJ Code Handle
//            {
//                string current_obj_code;
//                string instruction_as_op=_Instruction_Found_Get_INST(Instruction[i]);
//                reverse(instruction_as_op.begin(),instruction_as_op.end());
//                current_obj_code=String_To_Opcode_Change_Size_TO_X(instruction_as_op,6,'0');
//                reverse(current_obj_code.begin(),current_obj_code.end());
//                Ob_Code_For_Hte.push_back(current_obj_code);
//                    File_Write<<"               "<<current_obj_code<<"|"<<endl;
//                    current_Ob_For_Hte++;
//            }
//
//          else if(_Check_If_DECLERATION(Labels[i])!=RESB&&_Check_If_DECLERATION(Labels[i])!=RESW)
//            {
//                //imediate
//                if(Labels[i][0]=='#')
//                {
//                  string temp=abels[i].substr(1, Labels[i].size()))
//                    if(is_number(temp))
//                    {
//                        ob
//                    }
//                }
//                 ///Indirect Addressing
//                   if(Labels[i][Labels[i].size()-1]=='x'||Labels[i][Labels[i].size()-1]=='X')
//                  {
//                      Ob_Code_For_Hte.push_back(_Instruction_Found_Get_INST(Instruction[i])+_Hex_Indirect_CHANGER(_Get_Label_LOC(Labels[i].substr(0, Labels[i].size()- 1))));
//                    File_Write<<"               "<<_Instruction_Found_Get_INST(Instruction[i])+_Hex_Indirect_CHANGER(_Get_Label_LOC(Labels[i].substr(0, Labels[i].size()- 1)/* here we remove last char x*/))<<"|"<<endl; // if it word we store value in hex now we fit it in 6 digit
//                    current_Ob_For_Hte++;
//                  }
//                  else if(_Check_If_DECLERATION(Labels[i])==WORD)
//                  {
//                      Ob_Code_For_Hte.push_back(String_To_Opcode_Change_Size_TO_X(Instruction[i],6,'0'));
//                    File_Write<<"               "<<String_To_Opcode_Change_Size_TO_X(Instruction[i],6,'0')<<"|"<<endl; // if it word we store value in hex now we fit it in 6 digit
//                    current_Ob_For_Hte++;
//                  }
//
//                  ///Byte
//                   else if(_Check_If_DECLERATION(Labels[i])==BYTE)
//                   {
//                       string current_ob_code=Instruction[i];
//                       if(current_ob_code.size()>6)
//                       {
//                       vector<string> current_ob_code_for_hte;
//                       Object_Code_Fix_Exced_6(current_ob_code_for_hte,current_ob_code);
//                       for(int j=0;j<current_ob_code_for_hte.size();j++)
//                       {
//                       Ob_Code_For_Hte.push_back(current_ob_code_for_hte[j]);
//                       current_Ob_For_Hte++;
//                        if(j>=1)
//                        {
//                            reverse(current_ob_code_for_hte[j].begin(),current_ob_code_for_hte[j].end());
//                            current_ob_code_for_hte[j]=String_To_Opcode_Change_Size_TO_X(current_ob_code_for_hte[j],6,' ');
//                            reverse(current_ob_code_for_hte[j].begin(),current_ob_code_for_hte[j].end());
//                            File_Write<<"                          |                   "<<current_ob_code_for_hte[j]<<"|"<<endl;
//                        }
//                         else
//                       File_Write<<"               "<<current_ob_code_for_hte[j]<<"|"<<endl;
//                        if(j<current_ob_code_for_hte.size()-1)
//                        File_Write<<"                          |-------------------------|"<<endl;
//                       }
//                       }
//                       else
//                       {
//                        Ob_Code_For_Hte.push_back(current_ob_code);
//                       File_Write<<"               "<<current_ob_code<<"|"<<endl; // if it byte we store value in hex now we only display it
//                       current_Ob_For_Hte++;
//                       }
//                   }
//
//                   ///Label
//                   else if(Instruction[i]!="-1")
//                   {
//                        Ob_Code_For_Hte.push_back(_Instruction_Found_Get_INST(Instruction[i])+_Get_Label_LOC(Labels[i]));
//                       File_Write<<"               "<<_Instruction_Found_Get_INST(Instruction[i])+_Get_Label_LOC(Labels[i])<<"|"<<endl; //normal op code
//                       current_Ob_For_Hte++;
//                   }
//            }
//            else if(_Check_If_DECLERATION(Labels[i])==RESB||_Check_If_DECLERATION(Labels[i])==RESW)
//                    {
//                      Ob_Code_For_Hte.push_back("-1"); // handle if( we have resb or resw in middle)
//            File_Write<<"                     |"<<endl;
//                    }
//            else
//                File_Write<<"                     |"<<endl;
//            if(i<Labels.size()-2)
//            File_Write<<"                          |-------------------------|"<<endl;
//        }
//
//        Ob_Code_For_Hte.push_back("0"); //for end
//        File_Write<<"                           -------------------------"<<endl;
//        File_Write<<"==========================================================================================="<<endl;
//        File_Write<<"                                      HTE"<<endl;
//        File_Write<<"-------------------------------------------------------------------------------------------"<<endl;
//        File_Write<<"                                     Header"<<endl;
//        File_Write<<"			    ----------------------"<<endl;
//
//        ///Head
//        reverse(Prog_Name.begin(),Prog_Name.end());  //4akl
//        Prog_Name=String_To_Opcode_Change_Size_TO_X(Prog_Name,6,' '); //fit name 6 places 34an 4akl bas
//        reverse(Prog_Name.begin(),Prog_Name.end());  //4akl
//        File_Write<<"                           |H^"<<Prog_Name<<"^";
//        File_Write<<String_To_Opcode_Change_Size_TO_X(Prog_Loc_Counter_Array[0],6,'0')<<"^";
//        File_Write<<String_To_Opcode_Change_Size_TO_X(_String_Hex_DEC_X(Table[Table.size()-1].Label_Location,Prog_Loc_Counter_Array[0]),6,'0')<<"|"<<endl;
//        File_Write<<"			    ----------------------"<<endl;
//
//        ///Text
//        File_Write<<"                 ==============================================="<<endl;
//       int i=0,last=0,sum_bits=0,j=0;
//        vector <string> current_prog_length;  //store all program lengths in this vector
//         Prog_Length_Calc(Ob_Code_For_Hte,Prog_Loc_Counter_Array,current_prog_length);
//         for( i=0;i<current_prog_length.size();i++)
//         {
//             cout<<"A"<<current_prog_length[i]<<endl;
//                    ///Text
//                    File_Write<<"                                     Text : "<<i+1<<endl;
//                    File_Write<<"			    ----------------------"<<endl;
//                    File_Write<<" ---------------------------------------------------------------------------------------"<<endl;
//                    File_Write<<"|T^"<<String_To_Opcode_Change_Size_TO_X(Prog_Loc_Counter_Array[0],6,'0');
//                    File_Write<<"^"<<current_prog_length[i];
//
//                     for( j=last;(sum_bits+Ob_Code_For_Hte[j].size())<=60&&Ob_Code_For_Hte[j]!="-1"&&j<=Ob_Code_For_Hte.size();j++)
//                        {
//                            File_Write<<"^"<<Ob_Code_For_Hte[j];
//                            sum_bits+=Ob_Code_For_Hte[j].size();
//                        }
//                     if(Ob_Code_For_Hte[j]=="-1")
//                            j++;
//
//                    sum_bits=0;
//                    last=j;
//
//                    File_Write<<endl;
//                    File_Write<<" ---------------------------------------------------------------------------------------"<<endl;
//         }
//        ///End
//        File_Write<<"==========================================================================================="<<endl;
//        File_Write<<"                                      END"<<endl;
//        File_Write<<"-------------------------------------------------------------------------------------------"<<endl;
//        File_Write<<"                           	    --------"<<endl;
//        File_Write<<"                                   |E^"<<String_To_Opcode_Change_Size_TO_X(Prog_Loc_Counter_Array[0],6,'0')<<"|"<<endl;;
//        File_Write<<"                           	    --------"<<endl;
//      File_Write.close();
//
//   }
}
void test()
{

//    for(int i=0;i<Prog_Loc_Counter_Array.size();i++)
//    {
//        cout<<Prog_Loc_Counter_Array[i]<<"      "<<Instruction[i]<<endl;
//    }
//   cout<<"-----------------------------------"<<endl;
//   for(int i=0;i<LITERAL_Table.size();i++)
//        cout<<LITERAL_Table[i].Address<<"           "<<LITERAL_Table[i].LENGTH<<"          "<<LITERAL_Table[i].Value<<"      "<<LITERAL_Table[i].op_code_value<<endl;
//
//   cout<<"-----------------------------------"<<endl;
//  for(int i=0;i<Labels.size();i++)
//   {
//     cout<<Labels[i]<<endl;
//   }
//   cout<<"-----------------------------------"<<endl;
//   for(int i=0;i<Table.size()-1;i++)
//        cout<<Table[i].Label_Location<<"           "<<Table[i].Label<<endl;
//   cout<<"-----------------------------------"<<endl;
 // for(int i=0;i<Ob_Code_For_Hte.size();i++)
//   {
   //    cout<<Ob_Code_For_Hte[i]<<endl;
//   }
//   cout<<Prog_Loc_Counter_Array.size()<<"          "<<Labels.size()<<"       "<<Instruction.size()<<endl;
Prog_Loc_Counter_Array.push_back("0");
Instruction.push_back("0");
Instruction.push_back("0");
for(int i=0;i<Prog_Loc_Counter_Array.size();i++)
{
    cout<<Prog_Loc_Counter_Array[i]<<"          "<<Instruction[i]<<"        "<<Labels[i]<<endl;
}
}
