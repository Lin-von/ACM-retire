#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
double dp[1000+5][1000+5];

int main()
{
    int w,b;
    cin>>w>>b;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=w;i++) dp[i][0]=1;
    for(int i=1;i<=w;i++)
        for(int j=1;j<=b;j++)
    {
        dp[i][j]+=(double) i/(i+j);
        if(j-3>=0)
            dp[i][j]+=(double)j/(i+j)*((double)(j-1)/(i+j-1))*((double)(j-2)/(i+j-2))*dp[i][j-3];
        if(j-2>=0)
            dp[i][j]+=((double)j/(i+j))*((double)(j-1)/(i+j-1))*((double)i/(i+j-2))*dp[i-1][j-2];

    }
    cout<<fixed<<setprecision(9)<<dp[w][b]<<endl;
    return 0;
}
