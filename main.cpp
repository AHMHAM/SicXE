#include<bits/stdc++.h>
#include "scan.h"
#include "hex_inc_dec.h"
#include "Symbol_Table.h"
#include "Object_code_creator.h"
//#include"testoooo.h"
using namespace std;

//void test2();
//void Pass_TWO(string File_Path);

int main()
{

   string file_path="in_2.txt";
   cout<<"               Program Location Counter               "<<endl;
   cout<<"-------------------------------------------------------"<<endl;
   string file_output="out.txt";
    Pass_ONE(file_path);
    Pass_TWO(file_output);
    test();
//    //test2();
    return 0;
}

