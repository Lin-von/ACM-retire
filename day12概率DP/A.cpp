#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
double a[100000+5];
int b[100000+5];
int main()
{
    int n,m,x,y;
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        if(n==0&&m==0) break;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            b[x]=y;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(b[i]!=0) a[i]=a[b[i]];
            else
            for(int j=1;j<=6;j++)
            {
                a[i]+=(a[i+j]+1)/6;
            }
           // a[i]+=1;
        }
       // for(int i=0;i<=n;i++) cout<<a[i]<<' ';
       // cout<<endl;
        cout<<fixed<<setprecision(4)<<a[0]<<endl;

    }
    return 0;
}
