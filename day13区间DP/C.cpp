#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
int a[100+5];
int dp[100+5][100+5];
int sum[100+5];
int min(int a,int b)
{

    return a>b?b:a;
}
int main()
{
    int t;
    cin>>t;
    for(int w=1;w<=t;w++)
    {
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }

        for(int l=2;l<=n;l++)
            for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            for(int k=i;k<=j;k++)
            {
                if(dp[i][j]==0) dp[i][j]=dp[i+1][k]+dp[k+1][j]+(k-i)*a[i]+(sum[j]-sum[k])*(k-i+1);
                dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]+(k-i)*a[i]+(sum[j]-sum[k])*(k-i+1));
            }
        }
        cout<<"Case #"<<w<<": "<<dp[1][n]<<endl;
    }

    return 0;
}
