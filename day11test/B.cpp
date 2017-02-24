#include"iostream"
#include"string.h"
#include"queue"
using namespace std;
int dp[100+5][1000+5];
int v[1000+5];
int c[100+5],w[100+5];
priority_queue<int > q;
int main()
{
    int t,V,k,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>V>>k;
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++) cin>>c[i];
        memset(dp,0,sizeof(dp));
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=V;j++)

         {

            if(c[i]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
            if(!v[dp[i][j]]) {
            v[dp[i][j]]=1;
            q.push(dp[i][j]);
             }
         }
        // cout<<666<<endl;
         while(!q.empty()) {cout<<q.top()<<endl; q.pop();}
         while(k>1) {if(!q.empty()) q.pop(); k--;}
         if(q.empty()) cout<<0<<endl;
         else cout<<q.top()<<endl;

    }

    return 0;
}
