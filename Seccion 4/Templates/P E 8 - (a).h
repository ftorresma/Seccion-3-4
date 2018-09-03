#include <vector>
#include <string>
using namespace std;
class memberType
{
    string nombre;
    int ID, lib_comp, cant_gast, din;
public:
    memberType(string,int,int,int);
    void mos_nom();
    void mod_nom(string);
    void mos_lib_c();
    void mod_lib_c(int);
    void mos_cant_g();
    void mod_cant_g(int);
    void mos_id();
};


