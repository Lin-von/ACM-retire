#include"iostream"
#include"string.h"
using namespace std;
int a[100000+5];
int c[100000+5];
int main()
{
    int n,t;
    while(cin>>n>>t)
    {
        for(int i=1;i<=n;i++)
            {
                cin>>a[i];
                c[i]=0;
            }
        c[0]=0;

        while(t--)
        {
            int x,y;
            cin>>x>>y;
            c[x]++;
            c[y+1]++;
        }


        for(int i=1;i<n;i++)
        {
            c[i]+=c[i-1];
            cout<<(a[i]+c[i])%2<<' ';
        }
        c[n]+=c[n-1];
        cout<<(a[n]+c[n])%2<<endl;;
    }

    return 0;
}
