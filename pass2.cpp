#include "pass2.h"
void PASS_TWO(vector<string> &Labels,vector<string> &Instruction,
              vector<string> &Prog_Loc_Counter_Array,vector <Symbol_Table> &Table,
              vector<string> &Ob_Code_For_Hte,vector <Literal_Table> &LITERAL_Table)
{
    for(int i=0;i<Labels.size()-1;i++) // 34an ma5od4 ma3aya al location bata3 end
    {
       string ob=OBJECT_CODE_Create(Instruction[i] ,Labels[i] ,Prog_Loc_Counter_Array[i+1],Table,LITERAL_Table);
    cout<<ob<<"       "<<Prog_Loc_Counter_Array[i+1]<<"          "<<Instruction[i]<<"        "<<Labels[i]<<endl;
    //cout<<ob<<endl;
    cout<<"------------------------------------------"<<endl;
       Ob_Code_For_Hte.push_back(ob);

    }
}
