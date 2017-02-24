#include"iostream"
using namespace std;


int n,maxx;
int c[22][22];
int v[22];
void calc()
{
    int temp=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           if(v[i]&&!v[j]) temp+=c[i][j];
        if(temp>maxx) maxx=temp;
}
void dfs(int k)
{
    if(k==n)
    {
        calc();
        return;
    }
    v[k]=1;  dfs(k+1);
    v[k]=0;  dfs(k+1);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>c[i][j];
    for(int i=1;i<=n;i++) v[i]=0;
    dfs(1);
    cout<<maxx;
    return 0;

}
