#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
double dp[22][22][8][8][8];
double dfs(int x,int y,int z1,int z2,int z3)
{

    if(dp[x][y][z1][z2][z3]>=0) return dp[x][y][z1][z2][z3];
    if(y==0) return 1;
    if(x<y) return 0;
    int flag=0;
    if(z1+z2+z3<7) flag=1;
    double p1,p2,p3,p4;
    p1=dfs(x-1,y-1,z1,z2,z3);
    p2=0; p3=0; p4=0;
    if(z1>0)  p2=dfs(x-1,y,z1-1,z2,z3);
    if(z2>0)  p3=dfs(x-1,y,z1+1,z2-1,z3+flag);
    if(z3>0)  p4=dfs(x-1,y,z1,z2+1,z3-1+flag);
    dp[x][y][z1][z2][z3]=(double)(p1+z1*p2+z2*p3+z3*p4)/(1+z1+z2+z3);

    return dp[x][y][z1][z2][z3];
}
int main()
{
    int t;
    int x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>z;
        memset(dp,-1,sizeof(dp));
        cout<<fixed<<setprecision(6)<<dfs(x,y,0,0,z)<<endl;
    }
    return 0;
}
