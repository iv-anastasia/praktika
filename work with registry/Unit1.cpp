//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include <string.h>
#include "Registry.hpp"
//---------------------------------------------------------------------------
using namespace std;
#pragma argsused

int main(int argc, char* argv[])
{
SetConsoleOutputCP (1251);
SetConsoleCP (1251);
char choice;
HKEY hKey;
string way1;
string value1;
AnsiString way;
AnsiString value;
cout<<"1 - HKEY_LOCAL_MACHINE"<<endl;
cout<<"2 - HKEY_CURRENT_CONFIG"<<endl;
cout<<"3 - HKEY_CLASSES_ROOT"<<endl;
cout<<"4 - HKEY_USERS"<<endl;
cout<<"5 - HKEY_CURRENT_USER"<<endl;
cin>>choice;
switch(choice){
case '1': {hKey = HKEY_LOCAL_MACHINE; break;}
case '2': {hKey = HKEY_CURRENT_CONFIG; break;}
case '3': {hKey = HKEY_CLASSES_ROOT; break;}
case '4': {hKey = HKEY_USERS; break;}
case '5': {hKey = HKEY_CURRENT_USER; break;}
}
cout<<"¬ведите путь"<<endl;
cin>>way1;
cout<<"¬ведите новое значение"<<endl;
cin>>value1;
way =(AnsiString) way1.c_str();
value = (AnsiString)value1.c_str();
TRegistry *reg=new TRegistry();
reg->OpenKey(way,true);
reg->WriteString("",value);
reg->CloseKey();
delete reg;
system("pause");
        return 0;
}
//---------------------------------------------------------------------------
