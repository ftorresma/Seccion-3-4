#include <iostream>
#include <string>
#include <math.h>
using namespace std;

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>& operator=(const arrayListType<elemType>&);
void print() const;
void insertEnd(const elemType& insertItem);
void removeAt2(int location);
int seqSearch(const elemType& item) const;
void removeAll(const elemType& removeItem);
elemType min();
elemType max();

arrayListType(int size = 100);
~arrayListType();

protected:
        elemType *list;
        int length;
        int maxSize;
};

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
        cout << endl;
}
template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList)
{
    if (this != &otherList) {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new elemType[maxSize];
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (length >= maxSize)
        cerr << "Cannot insert in a full list" << endl;
    else{
        list[length] = insertItem;
        length++;
    }
}


template <class elemType>
void arrayListType<elemType>::removeAt2(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
        << "is out of range" << endl;
    else{
        list[location] = list[length-1];
        length--;
    }
}


template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0){
        cerr << "The array size must be positive. Creating "
        << "an array of size 100. " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;
        length = 0;
        list = new elemType[maxSize];
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}


template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;
    for (loc = 0; loc < length; loc++)
    if (list[loc] == item)
    {
        found = true;
        break;
    }
    if (found)
        return loc;
    else
        return -1;
}

template<class elemType>
void arrayListType<elemType>::removeAll(const elemType& removeItem)
{
    int loc;
    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        for(int i=0;i<length;i++){
            if(list[i]==removeItem){
                loc = seqSearch(removeItem);
                removeAt2(loc);
                i--;
            }
        }
    }
}

template<class elemType>
elemType arrayListType<elemType>::min()
{
    elemType minimo=list[0];
    for(int i=1;i<length;i++)
    {
        if(list[i]<minimo){
            minimo=list[i];
        }
    }
    return minimo;
}

template<class elemType>
elemType arrayListType<elemType>::max()
{
    elemType maximo=list[0];
    for(int i=1;i<length;i++)
    {
        if(list[i]>maximo){
            maximo=list[i];
        }
    }
    return maximo;
}



///////////  polinomios    //////////////


class polynomialType: public arrayListType<double>
{
    friend ostream& operator<<(ostream&, const polynomialType&);
    friend istream& operator>>(istream&, polynomialType&);
    friend polynomialType operator+ (const polynomialType&, const polynomialType&);
    friend polynomialType operator- (const polynomialType&, const polynomialType&);

    public:
    polynomialType operator~();
    polynomialType operator*(const polynomialType&);
    double operator() (double x);
    polynomialType(int size = 100);
    int min(int x, int y) const;
    int max(int x, int y) const;
};
polynomialType::polynomialType(int size)
: arrayListType<double>(size)
{
        length = size;
        for (int i = 0; i < size; i++)
        list[i] = 0;
}
double polynomialType::operator() (double x)
{
        double value = 0.0;
        for (int i = 0; i < length; i++){
            if (list[i] != 0.0)
            value = value + list[i] * pow(x,i);
        }
        return value;
}

int polynomialType::min(int x, int y) const
{
    if (x <= y)
    return x;
    else
    return y;
}
int polynomialType::max(int x, int y) const
{
    if (x >= y)
    return x;
    else
    return y;
}

/////    problema 5    ////////////
polynomialType operator+(const polynomialType& right,const polynomialType& right2)
{
    int size = max(right.length, right2.length);
    polynomialType temp(size);
    for (int i = 0; i < min(right.length, right2.length); i++)
        temp.list[i] = right.list[i] + right2.list[i];
    if (size == right.length)
        for (int i = min(right.length, right2.length); i < right.length; i++)
            temp.list[i] = right.list[i];
    else
        for (int i = min(right.length, right2.length); i < right2.length;i++)
            temp.list[i] = right2.list[i];
    return temp;
}

polynomialType operator-(const polynomialType& right, const polynomialType& right2)
{
    int size = max(right.length, right2.length);
    polynomialType temp(size);
    for (int i = 0; i < min(right.length, right2.length); i++)
        temp.list[i] = right.list[i] - right2.list[i];
    if (size == right.length)
        for (int i = min(right.length, right2.length); i < right.length; i++)
        temp.list[i] = right.list[i];
    else
        for (int i = min(right.length, right2.length); i < right2.length;i++)
        temp.list[i] = -right2.list[i];
    return temp;
}

///////   problema 6    //////////////////
polynomialType polynomialType::operator*(const polynomialType& right)
{
    int size = length +right.length;
    int i,j;
    polynomialType temp(size);
    polynomialType result(size);
    for(i=0;i<length;i++){
        for(j=0;j<right.length;j++){
            temp.list[i+j]=list[i] * right.list[j];
        }
        result =result + temp;
        temp= {};
    }
    return result;
}

polynomialType polynomialType::operator~(){
    int size=length;
    polynomialType temp(size);
    for(int i=1;i<length;i++){
        temp.list[i-1]=list[i]*i;
    }
    return temp;
}

ostream& operator<<(ostream& os, const polynomialType& p)
{
    int indexFirstNonzeroCoeff = 0;
    for (int i = 0; i < p.length; i++){
        if (p.list[i] != 0.0){
            indexFirstNonzeroCoeff = i;
            break;
        }
    }
    if (indexFirstNonzeroCoeff < p.length)
    {
        if (indexFirstNonzeroCoeff == 0)
            os << p.list[indexFirstNonzeroCoeff] << " ";
        else{
            os << p.list[indexFirstNonzeroCoeff] << "x^"
            << indexFirstNonzeroCoeff << " ";}
        for (int i = indexFirstNonzeroCoeff + 1; i < p.length; i++)
        {
            if (p.list[i] != 0.0)
                if (p.list[i] >= 0.0)
                    os << "+ " << p.list[i] << "x^" << i << " ";
                else
                    os << "- " << -p.list[i] << "x^" << i << " ";
        }

    }
    else
        os << "0";

    return os;

}
istream& operator>>(istream& is, polynomialType& p)
{
    cout << "The degree of this polynomial is: "
    << p.length - 1 << endl;
    for (int i = 0; i < p.length; i++)
    {
    cout << "Enter the coefficient of x^" << i << ": ";
    is >> p.list[i];
    }
    return is;
}



int main()
{
/*
arrayListType<int> intList(100);
arrayListType<string> stringList;
intList.insertEnd(1);
intList.insertEnd(8);
intList.insertEnd(5);
intList.insertEnd(9);
intList.insertEnd(4);
intList.print();
cout<<intList.max()<<endl;


stringList.insertEnd("a");
stringList.insertEnd("b");
stringList.insertEnd("c");
stringList.print();
cout<<stringList.max();

//intList.print();
//cout<<intList.listSize();
return 0;
*/
polynomialType p(2);
polynomialType q(5);
polynomialType t;
cin >> p;
cout << endl << "p(x): " << p << endl;
cout << "p(5): " << p(5) << endl << endl;
cin >> q;
cout << endl << "q(x): " << q << endl
<< endl;
t = p + q;
cout << "p(x) + q(x): " << t << endl;
cout << "p(x) - q(x): " << p - q << endl;
cout << "p(x) * q(x): " << p * q << endl;
cout << "Derivada: " << ~q << endl;

return 0;
}




