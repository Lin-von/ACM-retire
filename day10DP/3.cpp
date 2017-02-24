#include"iostream"
#include"string.h"
using namespace std;
int dp[1000+5][1000+5];
int sum[1000+5];
int main()
{
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    sum[1]=1;
    dp[1][1]=1;
    for(int i=2;i<=1000;i++)
        for(int j=1;j<=i;j++)
    {
        dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*j%10056;
        sum[i]=(sum[i]+dp[i][j])%10056;
    }
    int t;
    cin>>t;
    int x;
    for(int i=1;i<=t;i++)
    {
        cin>>x;
        cout<<"Case "<<i<<": "<<sum[x]<<endl;
    }
    return 0;
}
