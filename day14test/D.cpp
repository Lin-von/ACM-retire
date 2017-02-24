
#include"iostream"
#include"cmath"
#include"algorithm"
#include"string.h"
#include"vector"
using namespace std;
int n,m,k;
int x,y;
int flag;
vector<int > a[50+5];
int v[50+5];
void dfs(int cur,int dgr)
{
    if(v[cur]!=0)
        {
           if(dgr-v[cur]==k) flag=1;
           return;
        }
    if(flag==1) return;

    v[cur]=dgr;
    for(int i=0;i<a[cur].size();i++)
    {
        dfs(a[cur][i],dgr+1);
    }

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        flag=0;
        cin>>n>>m>>k;
        for(int i=0;i<n;i++) a[i].clear();
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);

        }

        for(int i=0;i<n;i++)
        {
            memset(v,0,sizeof(v));
            dfs(i,1);
            if(flag==1) break;
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
