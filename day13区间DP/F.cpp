#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
int dp[10000+5][500+5];

int a[10000+5];
int max(int a,int b)
{

    return a>b?a:b;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>a[i];

        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i-1][0];
            for(int j=1;j<=m;j++)
            {
                if(j<=i) dp[i][0]=max(dp[i][0],dp[i-j][j]);
                dp[i][j]=dp[i-1][j-1]+a[i];
            }
        }

        cout<<dp[n][0]<<endl;

    }
    return 0;
}
