#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    vector<int> prueb={1,2,3,4,5,6,7,8,9};
    float mean=0, dev=0;
    for(int i=0;i<prueb.size();i++)
        mean=mean+prueb[i];
    mean=mean/prueb.size();
    for(int i=0;i<prueb.size();i++)
        dev=(prueb[i]-mean)*(prueb[i]-mean)+dev;
    dev=sqrt(dev);
    cout<<mean<<endl;
    cout<<dev<<endl;
}
