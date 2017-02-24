#include"iostream"
#include"stdio.h"
#include"vector"
using namespace std;
int flag=0;
int n,m;
vector<int > g[100005];
vector<int > sum[2];
int type[100005];
int v[100005];
void dfs(int x,int last,int co)
{
    sum[co].push_back(x);
    type[x]=co;
    v[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        if(g[x][i]==last) continue;
        if(v[g[x][i]]&&type[g[x][i]]==type[x]) {flag=1; break;}
        if(v[g[x][i]]) continue;
         dfs(g[x][i],x,1-co);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) v[i]=0;
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);

    }
    for(int i=1;i<=n;i++)
    {
        if(flag==1) break;
        if(!v[i]) dfs(i,-1,0);
    }
    if(flag==1) cout<<-1<<endl;

    else
    {
        cout<<sum[0].size()<<endl;
        for(int i=0;i<sum[0].size();i++)
        cout<<sum[0][i]<<" ";
        cout<<endl;
        cout<<sum[1].size()<<endl;
        for(int i=0;i<sum[1].size();i++)
        cout<<sum[1][i]<<" ";
        cout<<endl;
    }
    return 0;
}
