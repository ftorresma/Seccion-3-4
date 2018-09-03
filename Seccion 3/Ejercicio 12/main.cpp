#include <iostream>

using namespace std;

class matrixType{
    friend ostream& operator<<(ostream&,matrixType&);
public:
    void operator+(matrixType&);
    void operator-(matrixType&);
    void operator*(matrixType&);
    matrixType(int,int);
    int r,c;
private:
    int **m;

};
matrixType::matrixType(int r,int c)
{
    this->r=r;
    this->c=c;
    m = new int* [r];
    for (int i = 0; i < r; i++)
        m[i] = new int[c];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout<<"ingrese elementos: ";
            cin>>m[i][j];
        }
    }
}
void matrixType::operator+(matrixType& p)
{
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout<<m[i][j] + p.m[i][j]<<" ";
        }
        cout << endl;
    }
}
void matrixType::operator-(matrixType& p)
{
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout<<m[i][j] - p.m[i][j]<<" ";
        }
        cout << endl;
    }
}
void matrixType::operator*(matrixType& p)
{
    int **q;
    q = new int* [r];
    for (int i = 0; i < r; i++)
        q[i] = new int[c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < p.c; j++)
            q[i][j]=0;

    cout<<endl;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < p.c; j++){
            for(int z=0; z<c; z++){
                  q[i][j]+= m[i][z] * p.m[z][j];
            }
        }
    }
     for (int i = 0; i < r; i++){
        for (int j = 0; j < p.c; j++){
             cout << q[i][j] << " ";
        }
        cout << endl;
    }
}

ostream& operator<<(ostream& os, matrixType& p)
{
    for (int i = 0; i < p.r; i++){
        for (int j = 0; j < p.c; j++){
            os << p.m[i][j] << " ";
        }
        cout << endl;
    }
    return os;
}

int main()
{
    matrixType m(2,2);
    cout<<m;
    matrixType p(2,2);
    cout<<p;
    cout<<endl;
    cout<<"suma: "<<endl;
    m+p;
    cout<<"resta: "<<endl;
    m-p;
    cout<<"multiplicacion: "<<endl;
    m*p;

}
