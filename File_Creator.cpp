#include"File_Creator.h"
using namespace std;
ifstream _File_Type_READ (string File_Path)
{
    ifstream File_Read(File_Path.c_str());
    return File_Read;
}
