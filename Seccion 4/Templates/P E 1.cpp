#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> candidatos;
    vector<float> votos;
    string candi;
    float cant_vot;
    while(cin>>candi)
    {
        if(candi!="arr")
        {
            cin>>cant_vot;
            candidatos.push_back(candi);
            votos.push_back(cant_vot);
        }
        else
            break;
    }
    cout<<"Candidato \t Votos Recibidos \t %del total de votos"<<endl;
    float total=0;
    for(int i=0;i<votos.size();i++)
    {
        total=total+votos[i];
    }
    for(int i=0;i<candidatos.size();i++)
    {
        cout<<candidatos[i]<<"\t \t \t";
        cout<<votos[i]<<"\t \t \t";
        cout<<(votos[i]*100)/total<<endl;
    }
    cout<<"Total \t"<<total<<endl;
    int a[2]={votos[0],0};
    for(int i=0;i<votos.size();i++)
    {
        if(votos[i]>a[0])
        {
            a[0]=votos[i];
            a[1]=i;
        }
    }
    cout<<"El ganador es "<<candidatos[a[1]];
    return 0;
}
