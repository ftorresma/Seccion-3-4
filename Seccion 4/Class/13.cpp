#include <iostream>
#include <vector>

using namespace std;

class largeIntegers
{
    int sig;
    vector<int> integer;
public:
    largeIntegers(int a)
    {
        sig=a;
    }
    void poner_dig(int a)
    {
        vector<int> t;
        t.push_back(a);
        for(int i=0;i<integer.size();i++)
        {
            t.push_back(integer[i]);
        }
        integer=t;
    }
    void poner(int a)
    {
        integer.push_back(a);
    }
    void most()
    {
        if(sig==-1)
            cout<<"-";
        for(int i=integer.size();i>0;i--)
        {
            cout<<integer[i-1];
        }
        cout<<endl;
    }
    int tam()
    {
        return integer.size();
    }
    int pos(int a)
    {
        return integer[a];
    }
    void camb(int a, int b)
    {
        integer[a]=b;
    }
    void camb_sig(int a)
    {
        sig=a;
    }
    int top_sig()
    {
        return sig;
    }
};
largeIntegers operator + (largeIntegers q,largeIntegers w)
{
    int may, men, gut=1;
    largeIntegers e(1),f(1);
    if(q.tam()>w.tam())
    {
        may=q.tam();
        e=q;
        f=w;
        men=w.tam();
    }
    else
    {
        may=w.tam();
        e=w;
        f=q;
        men=q.tam();
    }
    if(q.tam()==w.tam())
    {
        for(int i=0;i<may;i++)
        {
            if(q.pos(q.tam()-1-i)>w.pos(w.tam()-1-i))
            {
                may=q.tam();
                e=q;
                f=w;
                men=w.tam();
                break;
            }
            else if (q.pos(q.tam()-1-i)<w.pos(w.tam()-1-i))
            {
                may=w.tam();
                e=w;
                f=q;
                gut=-1*e.top_sig();
                men=q.tam();
                break;
            }
        }
    }
    if(q.top_sig()==w.top_sig())
    {
        for(int i=0;i<men;i++)
        {
            if(q.pos(i)+w.pos(i)>9)
            {
                if(i==may-1)
                {
                    e.camb(i,e.pos(i)+f.pos(i)-10);
                    e.poner(1);
                }
                else
                {
                    e.camb(i,e.pos(i)+f.pos(i)-10);
                    e.camb((i+1),(e.pos(i+1)+1));
                }
            }
            else
            {
                e.camb(i,e.pos(i)+f.pos(i));
            }
        }
    }
    else
    {
        for(int i=0;i<men;i++)
        {

            if(q.pos(i)<w.pos(i))
            {
                e.camb(i,(e.pos(i)+10)-f.pos(i));
                e.camb((i+1),(e.pos(i+1)-1));
            }
            else
            {
                e.camb(i,e.pos(i)-f.pos(i));
            }
        }
    }
    return e;
}

largeIntegers operator - (largeIntegers q,largeIntegers w)
{
    int may, men, gut=1;
    largeIntegers e(1),f(1);
    if(q.tam()>=w.tam())
    {
        may=q.tam();
        e=q;
        f=w;
        men=w.tam();
    }
    else
    {
        may=w.tam();
        e=w;
        f=q;
        gut=-1*gut;
        men=q.tam();
    }
    if(q.tam()==w.tam())
    {
        for(int i=0;i<may;i++)
        {
            if(q.pos(q.tam()-1-i)>w.pos(w.tam()-1-i))
            {
                may=q.tam();
                e=q;
                f=w;
                men=w.tam();
                break;
            }
            else if (q.pos(q.tam()-1-i)<w.pos(w.tam()-1-i))
            {
                may=w.tam();
                e=w;
                f=q;
                gut=-1*gut;
                men=q.tam();
                break;
            }
        }
    }
    if(q.top_sig()==w.top_sig())
    {
        for(int i=0;i<men;i++)
        {

            if(q.pos(i)<w.pos(i))
            {
                e.camb(i,(e.pos(i)+10)-f.pos(i));
                e.camb((i+1),(e.pos(i+1)-1));
            }
            else
            {
                e.camb(i,e.pos(i)-f.pos(i));
            }
        }
    }
    else
    {
        for(int i=0;i<men;i++)
        {
            if(q.pos(i)+w.pos(i)>9)
            {
                if(i==may-1)
                {
                    e.camb(i,e.pos(i)+f.pos(i)-10);
                    e.poner(1);
                }
                else
                {
                    e.camb(i,e.pos(i)+f.pos(i)-10);
                    e.camb((i+1),(e.pos(i+1)+1));
                }
            }
            else
            {
                e.camb(i,e.pos(i)+f.pos(i));
            }
        }
    }
    e.camb_sig(gut*e.top_sig());

    return e;
}

largeIntegers operator * (largeIntegers a, largeIntegers b)
{
    largeIntegers c(1), d(1), r(1), t(1);
    int may=b.tam();
    if(a.tam()>b.tam())
        may=a.tam();
    c.poner_dig(0);
    d.poner_dig(0);
    int q=0, w=1, e=0, f;
    for(int i=0;i<a.tam();i++)
    {
        for(int j=0;j<b.tam();j++)
        {
            e=(w*b.pos(j)*a.pos(i));
            while(e!=0)
            {
                r.poner(e%10);
                e=(e-(e%10))/10;
            }
            d=d+r;
            w=w*10;
            r=t;
        }
        for(int j=0;j<q;j++)
        {
            d.poner_dig(0);
        }
        c=c+d;
        d=t;
        d.poner_dig(0);
    }
    return c;
}

int main()
{
    largeIntegers pri(-1), seg(-1), tri(1);
    pri.poner_dig(1);
    pri.poner_dig(2);
    pri.poner_dig(3);
    pri.poner_dig(4);
    pri.poner_dig(5);
    pri.poner_dig(5);
    seg.poner_dig(9);
    seg.poner_dig(9);
    seg.poner_dig(9);
    seg.poner_dig(1);
    seg.poner_dig(1);
    seg.poner_dig(1);
    pri.most();
    seg.most();
    pri=seg-pri;
    pri.most();
    largeIntegers lo(1),wo(1);
    lo.poner_dig(1);
    lo.poner_dig(4);
    wo.poner_dig(8);
    wo.poner_dig(9);
    lo.most();
    wo.most();
    lo=lo*wo;
    lo.most();
}
