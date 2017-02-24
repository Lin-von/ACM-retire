#include"iostream"
#include"string.h"
#include"memory.h"
using namespace std;
int t[17][17];
int v[18];
int n;
int maxx;
void dfs(int s,int step,int last)
{
    if(step>maxx)  maxx=step;
    for(int i=0;i<n;i++)
        if(t[s][i]>=last&&!v[i]&&i!=s)
    {
        v[i]=1;
        dfs(i,step+1,t[s][i]);
        v[i]=0;
    }
}
int main()
{
    //int n;
    while(cin>>n)
    {
        maxx=-1e8;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>t[i][j];
        /*for(int k=0;k<n;k++)
        {*/
            memset(v,0,sizeof(v));
            v[0]=1;
            dfs(0,1,0);

       // }
        cout<<maxx<<endl;
    }

    return 0;
}
