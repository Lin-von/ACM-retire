#include"iostream"
#include"stack"
using namespace std;
int a[105][105],f[105][105];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        cin>>a[i][j];
    for(int i=1;i<=n;i++)
        f[n][i]=a[n][i];
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
        f[i][j]= max( f[i+1][j] , f[i+1][j+1] )+a[i][j];
    cout<<f[1][1]<<endl;
    int x,y;
    x=1; y=1;
    cout<<a[1][1];
    while(x<n)
    {
        if(f[x+1][y]>f[x+1][y+1]) {cout<<' '<<a[x+1][y]; x++;}
        else {cout<<' '<<a[x+1][y+1]; x++;y++;}
    }
    return 0;
}
