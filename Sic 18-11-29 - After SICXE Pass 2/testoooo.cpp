#include "testoooo.h"
void printo(vector <Symbol_Table> &symbol)
{
    for(int i=0;i<symbol.size();i++)
    {
        cout << "label is: " << symbol[i].Label <<"         "<<"Label_Location is: " << symbol[i].Label_Location<<endl ;
    }
}
