#include"iostream"
#include"string.h"
using namespace std;
int maxx=0;
int k,n;
int a[100+5][100+5];
int v[100+5][100+5];
dfs(int x,int y,int sum)
{
    v[x][y]=sum;
    sum+=a[x][y];

    if(sum>maxx) maxx=sum;
    for(int i=0;i<=k;i++)
    {
        if(x-i>=0&&sum>v[x-i][y]&&a[x-i][y]>a[x][y]) dfs(x-i,y,sum);
        if(y-i>=0&&sum>v[x][y-i]&&a[x][y-i]>a[x][y]) dfs(x,y-i,sum);
        if(x+i<n&&sum>v[x+i][y]&&a[x+i][y]>a[x][y]) dfs(x+i,y,sum);
        if(y+i<n&&sum>v[x][y+i]&&a[x][y+i]>a[x][y]) dfs(x,y+i,sum);
    }

}
int main()
{

    while(cin>>n>>k)
    {
        maxx=0;
        if(n==-1) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>a[i][j];
        memset(v,0,sizeof(v));
        dfs(0,0,0);
        cout<<maxx<<endl;
    }
    return 0;
}
