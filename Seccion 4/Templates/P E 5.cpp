#include <iostream>
#include <vector>

using namespace std;
template<class T>
int seqSearch(vector<T> &vec, const T& item)
{
    return vec[item-1];

}
int main()
{
    vector<int> prueb= {1,223,3,4,5};
    for(int i=0;i<prueb.size();i++)
        cout<<prueb[i];
    cout<<endl;
    cout<<seqSearch(prueb,2);
}
