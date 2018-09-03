#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> alumnos;
    vector<float> puntajes;
    string alum;
    float punt;
    while(cin>>alum)
    {
        if(alum!="arr")
        {
            cin>>punt;
            alumnos.push_back(alum);
            puntajes.push_back(punt);
        }
        else
            break;
    }
    float total=0;
    for(int i=0;i<puntajes.size();i++)
    {
        total=total+puntajes[i];
    }
    total=total/puntajes.size();
    cout<<"En promedio de las notas de la clase es: "<<total<<endl;
    cout<<"A los siguientes alumnos: "<<endl;
    for(int i=0;i<alumnos.size();i++)
    {
        if(total>=puntajes[i])
            cout<<alumnos[i]<<endl;
    }
    cout<<"no lograron pasar el promedio por ente estan";
    cout<<"deberan tomar clases de reforzamiento"<<endl;
    int a[2]={0,0};
    for(int i=0;i<alumnos.size();i++)
    {
        if(a[0]<=puntajes[i])
        {
            a[0]=puntajes[i];
            a[1]=i;
        }
    }
    cout<<"El mayor puntajes fue "<<a[0]<<" del alumno "<<alumnos[a[1]]<<endl;
    cout<<"Y los siguientes alumnos aprobaron:"<<endl;
     for(int i=0;i<alumnos.size();i++)
    {
        if(total<puntajes[i])
            cout<<alumnos[i]<<endl;
    }
    return 0;
}
