#include"iostream"
#include"string.h"
using namespace std;
int dp[50*180];
int c[55];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int t,v,n,cnt=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>v;
        for(int i=1;i<=n;i++) cin>>c[i];
        memset(dp,0x80,sizeof(dp));
        dp[0]=0;
        for(int i = 1;i <= n;i++)
            for(int j = v-1;j >=c[i];j--)
                dp[j] = max(dp[j],dp[j-c[i]]+1);
         int x=v-1;
         for(int i=v-1;i>=0;i--)
            if(dp[i]>dp[x]) x=i;
         //for(int i=1;i<v;i++) cout<<dp[i]<<endl;
         cout<<"Case "<<cnt++<<": ";
         cout<<dp[x]+1<<' '<<x+678<<endl;


    }
    return 0;
}
