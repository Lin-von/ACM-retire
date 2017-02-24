#include"iostream"
#include"string.h"
using namespace std;
int dp[1000+5];
int c[1000+5],w[1000+5];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int t;
    int n,V;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n>>V;
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++) cin>>c[i];

        for(int i=1;i<=n;i++)
            for(int j=V;j>=c[i];j--)
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        cout<<dp[V]<<endl;
    }
    return 0;
}
