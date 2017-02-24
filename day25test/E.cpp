#include"iostream"
#include"string.h"
#include"algorithm"
using namespace std;
int a[1000+5];
int v[1000+5];
int main()
{
    int n,m;
    int cas=1;
    while(cin>>m>>n)
    {
        if(m==0&&n==0) break;
        int sum=0;
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++)
           {
               cin>>a[i];
               v[a[i]]=1;
           }
           sort(a,a+n);
        for(int i=n-1;i>=0;i--)
        {
            int temp=a[i];
            while(v[temp]) temp++;
            if(temp<=n*m)
            {
                v[temp]=1;
            }
            else sum++;
        }

        cout<<"Case "<<cas++<<": "<<sum<<endl;
    }

    return 0;
}
