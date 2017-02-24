#include"iostream"
#include"string.h"
using namespace std;
int dp[40];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[1]=2;
    dp[2]=4;
    dp[3]=7;
    for(int i=4;i<=31;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    int x,w;

    while(cin>>x)
    {
        if(x==0) break;
        if(x<3) { cout<<0<<endl; continue;}
        w=1<<x;
        cout<<w-dp[x]<<endl;
    }

    return 0;
}
