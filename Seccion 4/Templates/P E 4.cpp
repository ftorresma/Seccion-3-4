#include <iostream>
#include <vector>

using namespace std;
template<class T>
void reverseVector(vector<T> &vec)
{
    int temp, a=vec.size()-1;
    for(int i=0;i<vec.size()/2;i++)
    {
        temp=vec[a];
        vec[a]=vec[i];
        vec[i]=temp;
        a--;
    }
}
int main()
{
    vector<int> prueb= {1,2,3,4,5};
    for(int i=0;i<prueb.size();i++)
        cout<<prueb[i];
    cout<<endl;
    reverseVector(prueb);
    for(int i=0;i<prueb.size();i++)
        cout<<prueb[i];
}
