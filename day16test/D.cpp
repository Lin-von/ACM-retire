#include"iostream"
#include"string"
#include"string.h"
//#include"memory.h"
using namespace std;
int a[1000+5],b[1000+5];
long long  f[1000+5][1000+5];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(f,0,sizeof(f));

        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                f[i][j]=(f[i-1][j]+f[i][j-1]-f[i-1][j-1]+1000000007)%1000000007;
                if(a[i]==b[j]) f[i][j]= (f[i][j]+f[i-1][j-1]+1)%1000000007;

            }

        cout<<f[n][m]%1000000007<<endl;
    }
    return 0;
}
