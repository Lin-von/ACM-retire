#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
int a[100+5];
int b[100+5];
int dp[100+5][100+5];
int sum[100+5][100+5];
int min(int a,int b)
{

    return a>b?b:a;
}

int main()
{
    int l,n;

    while(cin>>l)
    {
        if(l==0) break;
        memset(dp,0x7f,sizeof(dp));
        memset(sum,0,sizeof(sum));
        cin>>n;
        a[0]=0;
        for(int i=1;i<=n;i++)
             cin>>b[i];
        b[n+1]=l;
        for(int i=1;i<=n+1;i++)
            a[i]=b[i]-b[i-1];
        n++;
        for(int i=1;i<=n;i++)
        {
            sum[i][i]=a[i];
            dp[i][i]=0;
            for(int j=i+1;j<=n;j++)
                sum[i][j]=sum[i][j-1]+a[j];
        }

        for(int l=2;l<=n;l++)
          for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;

            for(int k=i;k<=j-1;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[i][j]);

        }
        cout<<"The minimum cutting is "<<dp[1][n]<<"."<<endl;

    }
    return 0;
}
