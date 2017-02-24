#include"iostream"
#include"string.h"
using namespace std;
int n=32005;

int c[32000+5];
int l[32000+5];
int lowbit(int x)
{
    return x&(-x);
}

int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}

int add(int i,int val)
{
    while(i<=n)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}

int main()
{
    int t;
    while(cin>>t)
    {
        int x,y;
        memset(c,0,sizeof(c));
        memset(l,0,sizeof(l));
        for(int i=0;i<t;i++)
        {
            cin>>x>>y;
            add(x+1,1);
            l[sum(x+1)-1]++;
        }
        for(int i=0;i<t;i++)
            cout<<l[i]<<endl;
    }

    return 0;
}
