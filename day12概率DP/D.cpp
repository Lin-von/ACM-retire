#include"iostream"
#include"string.h"
#include"stdio.h"
#include"cmath"
#include"iomanip"
using namespace std;
double dp[1000+5][1000+5];
double p1[1000+5][1000+5],p2[1000+5][1000+5],p3[1000+5][1000+5];
int main()
{
    int r,c;
    while(~scanf("%d%d",&r,&c))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            scanf("%lf%lf%lf",&p1[i][j],&p2[i][j],&p3[i][j]);

        for(int i=r;i>=1;i--)
            for(int j=c;j>=1;j--)
        {
            if(i==r&&j==c) continue;
            if(fabs(p1[i][j]-1)<0.000001) continue;
            dp[i][j]=(p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2)/(1-p1[i][j]);
        }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}
