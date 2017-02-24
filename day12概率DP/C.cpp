#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
double dp[100005];
int main()
{
    double sum=0;
    int n,m;
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    for(int i=2;i<=m;i++)
        dp[i]=(1-dp[i-1])*dp[i-1]+dp[i-1]*(dp[i-1]-(double)1/n);

    for(int i=1;i<=m;i++) sum+=dp[i];
    cout<<fixed<<setprecision(9)<<sum<<endl;
    return 0;
}
