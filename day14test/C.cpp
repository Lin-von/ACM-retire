#include"iostream"
#include"string.h"
#include"algorithm"
using namespace std;
int dp[5000+5];

struct node{
   int p,q,v;
};
int max(int a,int b)
{
    return a>b?a:b;
}

node nd[500+5];
int cmp(node a,node b)
{
    return a.q-a.p<b.q-b.p;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++) cin>>nd[i].p>>nd[i].q>>nd[i].v;
        sort(nd,nd+n,cmp);
        memset(dp,0,sizeof(dp));


        for(int i=0;i<n;i++)
            for(int j=m;j>=nd[i].q;j--)
            dp[j]=max(dp[j],dp[j-nd[i].p]+nd[i].v);
        cout<<dp[m]<<endl;
    }
    return 0;
}
