#include <vector>
#include <string>
using namespace std;


class cliente
{
    string nombre;
    vector<string> lib_comp;
    int ID;
    float cant_gast, dinero;
public:
    cliente(string,int,vector<string>,float,float);
    void mos_nom();
    void mod_nom(string);
    void mos_lib_c();
    void mod_lib_c(vector<string>);
    void mos_cant_g();
    void mod_cant_g(float);
    void mos_id();
    void mos_din();
    void comprar_lib(string,float);
};

class miembro
{
    string nombre;
    vector<string> lib_comp;
    int ID, cant_lib_comp=0, dias=0;
    float cant_gast, dinero, descuento=9.5;
public:
    miembro(string,int,vector<string>,float,float);
    void mos_nom();
    void mod_nom(string);
    void mos_lib_c();
    void mod_lib_c(vector<string>);
    void mos_cant_g();
    void mod_cant_g(float);
    void mos_id();
    void mos_din();
    void comprar_lib(string,float);
};

