//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include <string.h>
#include <Windows.h>
//---------------------------------------------------------------------------

#pragma argsused
using namespace std;
int main(int argc, char* argv[])
{
SetConsoleOutputCP (1251);
SetConsoleCP (1251);
char choice;
HKEY hKey;
string way1;
LPCTSTR way;
DWORD value = 0;
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
cout<<"������� ����"<<endl;
cin>>way1;
way = (LPCTSTR)way1.c_str();
cout<<"������� ����� ��������"<<endl;
cin>>value;
if(RegOpenKeyEx(hKey, way, 0, KEY_READ,&hKey)== ERROR_SUCCESS){
    RegSetValueEx(hKey, NULL,0,REG_SZ,(const BYTE*)&value, sizeof(value));
    cout<<"������"<<endl;
    }
else
    cout<<"�������� ������"<<endl;
RegCloseKey(hKey);
system("pause");
        return 0;
}
//---------------------------------------------------------------------------
