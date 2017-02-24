#include"iostream"
#include"string.h"
using namespace std;
double dp[102*102];
int m[102];
double p[102];
int maxm;
double max(double a,double b)
{
    return a>b?a:b;
}
int main()
{
    int t;
    cin>>t;
    double P;
    int n;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        maxm=0;
        cin>>P>>n;
        P=1-P;
        for(int i=1;i<=n;i++)
        {
            cin>>m[i]>>p[i];
            p[i]=1-p[i];
            maxm+=m[i];
        }
        //cout<<1<<endl;

        dp[0]=1;
        for(int i=1;i<=n;i++)
            for(int j=maxm;j>=m[i];j--)
            dp[j]=max(dp[j],dp[j-m[i]]*p[i]);
      //  for(int i=0;i<=maxm;i++) cout<<dp[i]<<endl;
       // cout<<P<<endl;
        for(int i=maxm;i>=0;i--)
        {
           // cout<<dp[i]<<' '<<P<<endl;
            if(dp[i]>P)
            {
                cout<<i<<endl;
                break;
            }
        }


    }
    return 0;
}
