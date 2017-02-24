#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
int a[100+5];
int dp[100+5][100+5];
int min(int a,int b)
{

    return a>b?b:a;
}
int main()
{
    int n;
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int l=3;l<=n;l++)
            for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            for(int k=i+1;k<j;k++)
                if(dp[i][j]==0) dp[i][j]=dp[i][k]+dp[k][j]+a[i]*a[k]*a[j];
                else dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
        }
        cout<<dp[1][n]<<endl;
    }
    return 0;
}
