#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<float> numeros;
    float num;
    while(cin>>num)
    {
        if(num!=0)
        {
            numeros.push_back(num);
        }
        else
            break;
    }
    float mini=numeros[0],maxi=numeros[0], total=0;
    for(int i=0;i<numeros.size();i++)
    {
        if(mini>numeros[i])
            mini=numeros[i];
        if(maxi<numeros[i])
            maxi=numeros[i];
        total=total+numeros[i];
    }
    total=total/numeros.size();
    cout<<"El numero mas grande es: "<<maxi<<endl;
    cout<<"El numero mas pequeño es: "<<mini<<endl;
    cout<<"El promedio es: "<<total<<endl;
    return 0;
}
