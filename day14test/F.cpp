#include"iostream"
#include"stdio.h"
#include"map"
using namespace std;
long long a[100000+5];
long long f[35];
map<long long ,long long > m;
int main()
{
    int n;
    f[1]=2;
    for(int i=2;i<=32;i++) f[i]=f[i-1]*2;
    while(cin>>n)
    {
        m.clear();
        long long sum=0;
        for(int i=1;i<=n;i++)
            { cin>>a[i]; m[a[i]]++;}

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=32;j++)
                if(f[j]>a[i])
            {
                long long temp=f[j]-a[i];
                sum+=m[temp];
                if(temp==a[i]) sum--;
            }
        }

        cout<<sum/2<<endl;
    }

    return 0;
}

