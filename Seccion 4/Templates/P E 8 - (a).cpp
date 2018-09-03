#include <iostream>
#include "P E 8 - (a).h"


memberType::memberType(string nomb,int lib_c,int cant_g,int i_d)
{
    nombre=nomb;
    cant_gast=cant_g;
    ID=i_d;
}
void memberType::mos_nom()
{
    cout<<nombre<<endl;
}
void memberType::mod_nom(string nomb)
{
    nombre=nomb;
}
void memberType::mos_lib_c()
{
    cout<< lib_comp<<endl;
}
void memberType::mod_lib_c(int lib_c)
{
    lib_comp=lib_c;
}
void memberType::mos_cant_g()
{
    cout<<cant_gast<<endl;
}
void memberType::mod_cant_g(int cant_g)
{
    cant_gast=cant_g;
}
void memberType::mos_id()
{
    cout<<ID<<endl;
}
int main()
{
    vector<string> arr;
    arr.push_back("Mario vargas");
    arr.push_back("Ciro Alegria");
}
