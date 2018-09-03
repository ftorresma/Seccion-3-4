#include <iostream>
#include <vector>
#include <string>

using namespace std;

class libreta_linea
{
    vector<string> nombre;
    vector<vector<string>> familiares, amigos, socios;
    vector<int> direccion, telefonos;
    vector<vector<int>> fecha_naci_familiares;
public:
    void set_persona(string nom,vector<string> famil,vector<int> fech_famil,vector<string> amig,vector<string> soci,int dire,int tele)
    {
        nombre.push_back(nom);
        familiares.push_back(famil);
        fecha_naci_familiares.push_back(fech_famil);
        amigos.push_back(amig);
        socios.push_back(soci);
        direccion.push_back(dire);
        telefonos.push_back(tele);
    }
};

int main()
{
    vector<string> arr;
    arr.push_back("La ciudad y los perros");
    arr.push_back("El burro");
}
