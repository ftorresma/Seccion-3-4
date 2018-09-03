#include <iostream>
#include "P E 8 - (b).h"

cliente::cliente(string nomb,int i_d,vector<string> lib_c,float cant_g,float din)
{
    nombre=nomb;
    ID=i_d;
    lib_comp=lib_c;
    cant_gast=cant_g;
    dinero=din;
}
void cliente::mos_nom()
{
    cout<<nombre<<endl;
}
void cliente::mod_nom(string nomb)
{
    nombre=nomb;
}
void cliente::mos_lib_c()
{
    for(int i=0;i<lib_comp.size();i++)
        cout<<lib_comp[i]<<endl;
}
void cliente::mod_lib_c(vector<string> lib_c)
{
    lib_comp=lib_c;
}
void cliente::mos_cant_g()
{
    cout<<cant_gast<<endl;
}
void cliente::mod_cant_g(float cant_g)
{
    cant_gast=cant_g;
}
void cliente::mos_id()
{
    cout<<ID<<endl;
}
void cliente::mos_din()
{
    cout<<dinero<<endl;
}
void cliente::comprar_lib(string lib, float cost)
{
    if(dinero>=cost){
        lib_comp.push_back(lib);
        dinero=dinero-cost;
        cant_gast=cant_gast+cost;}
}

miembro::miembro(string nomb,int i_d,vector<string> lib_c,float cant_g,float din)
{
    nombre=nomb;
    ID=i_d;
    lib_comp=lib_c;
    cant_gast=cant_g;
    dinero=din;
}
void miembro::mos_nom()
{
    cout<<nombre<<endl;
}
void miembro::mod_nom(string nomb)
{
    nombre=nomb;
}
void miembro::mos_lib_c()
{
    for(int i=0;i<lib_comp.size();i++)
        cout<<lib_comp[i]<<endl;
}
void miembro::mod_lib_c(vector<string> lib_c)
{
    lib_comp=lib_c;
}
void miembro::mos_cant_g()
{
    cout<<cant_gast<<endl;
}
void miembro::mod_cant_g(float cant_g)
{
    cant_gast=cant_g;
}
void miembro::mos_id()
{
    cout<<ID<<endl;
}
void miembro::mos_din()
{
    cout<<dinero<<endl;
}

void miembro::comprar_lib(string lib, float cost)
{
    if(dinero>=cost*descuento){
        lib_comp.push_back(lib);
        dinero=dinero-cost*descuento;
        cant_gast=cant_gast+cost*descuento;
        cant_lib_comp++;}
    if(cant_lib_comp==11){
        cant_lib_comp=0;
        descuento=descuento-0.01;}
}

int main()
{
    vector<string> arr;
    arr.push_back("La ciudad y los perros");
    arr.push_back("El burro");
}
