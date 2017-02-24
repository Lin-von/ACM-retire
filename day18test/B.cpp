#include"iostream"
#include"string.h"
using namespace std;
int dp[100+5][100+5];
int a[100+5][100+5];
int p[100+5];
int main()
{

    int f,v;
    cin>>f>>v;
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(0));
    memset(p,0,sizeof(p));

    for(int i=1;i<=f;i++)
        for(int j=1;j<=v;j++)
        cin>>a[i][j];

    for(int i=1;i<=f;i++)
        dp[i][i]=dp[i-1][i-1]+a[i][i];
    for(int i=1;i<=f;i++)
        for(int j=i+1;j<=v;j++)
        dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);

    for(int i=f,j=v;i>=1;i--)
    {
        while(j>=i)
        {
            if(dp[i][j]==dp[i-1][j-1]+a[i][j])
            {
                p[i]=j;
                j--;
                break;
            }
            j--;
        }
    }

    cout<<dp[f][v]<<endl;
    for(int i=1;i<f;i++)
        cout<<p[i]<<' ';
    cout<<p[f]<<endl;

        return 0;

}
