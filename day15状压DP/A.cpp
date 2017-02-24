#include"iostream"
#include"string.h"
#include"cmath"
#include"string"
using namespace std;
string s;
int n,m,k;
int v[8+2];
int sum;
char g[8+2][8+2];
int dp[8+2][1<<9+2];
void dfs(int cur,int cnt)
{
    if(cnt==k) {sum++; return;}
    if(cur>n) return;
    dfs(cur+1,cnt);
    for(int i=1;i<=n;i++)
    {
        if(g[cur][i]=='#'&&!v[i])
        {
            v[i]=1;
            dfs(cur+1,cnt+1);
            v[i]=0;
        }
    }
}
int main()
{

    while(cin>>n>>k)
    {
        sum=0;
        if(n==-1&&k==-1) break;
        memset(dp,0,sizeof(dp));
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++)

            for(int j=1;j<=n;j++)
            {
                cin>>g[i][j];
            }

        dfs(1,0);
        cout<<sum<<endl;

    }
    return 0;
}
