#include <vector>
#include <string>
using namespace std;
class bookType
{
    string titulo_Real;
    string titulo, editor;
    vector<string> autores;
    int ISBN, precio, fech_publi, cop_stock;
public:
    bookType(string,vector<string>,string,int,int,int,int);
    void mos_tit();
    void camb_tit(string);
    bool ver_tit();
    void mos_cop();
    void act_cop(int);
    int num_cop(int);
    void mos_ISBN();
    void act_ISBN(int);
    int num_ISBN(int);
    void mos_prec();
    void act_prec(int);
    int num_prec(int);
    void mos_aut();
    void act_aut(vector<string>);
    int num_aut(int);
    void fecha();
    void edit();
};
