#include <iostream>
#include "P E 7.h"


bookType::bookType(string titul,vector<string> aut_ores, string edi_tor, int ISB, int prec_io, int fech_a, int copias)
{
    titulo_Real=titul;
    autores=aut_ores;
    editor=edi_tor;
    ISBN=ISB;
    precio=prec_io;
    fech_publi=fech_a;
    cop_stock=copias;
}

void bookType::mos_tit()
{
    cout<<titulo<<endl;
}

void bookType::camb_tit(string titu)
{
    titulo=titu;
}
bool bookType::ver_tit()
{
    if(titulo==titulo_Real)
        return true;
    return false;
}
void bookType::mos_cop()
{
    cout<<cop_stock<<endl;
}
void bookType::act_cop(int copi)
{
    cop_stock=copi;
}
int bookType::num_cop(int copi)
{
    return cop_stock;
}
void bookType::mos_ISBN()
{
    cout<<ISBN<<endl;
}
void bookType::act_ISBN(int is)
{
    ISBN=is;
}
int bookType::num_ISBN(int is)
{
    return ISBN;
}
void bookType::mos_prec()
{
    cout<<precio<<endl;
}
void bookType::act_prec(int preci)
{
    precio=preci;
}
int bookType::num_prec(int preci)
{
    return preci;
}
void bookType::mos_aut()
{
    for(int i=0;i<autores.size();i++)
    {
        cout<<autores[i]<<endl;
    }
}
void bookType::act_aut(vector<string> aut)
{
    autores=aut;
}
int bookType::num_aut(int aut)
{
    return autores.size();
}
void bookType::fecha()
{
    cout<<fech_publi<<endl;
}
void bookType::edit()
{
    cout<<editor<<endl;
}
int main()
{
    vector<string> arr;
    arr.push_back("Mario vargas");
    arr.push_back("Ciro Alegria");
    bookType nat("Freno",arr,"Tacca",48,85,1945,25);
    nat.edit();
    nat.mos_aut();
}
