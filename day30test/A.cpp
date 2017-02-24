#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;
int a[100000+10][11];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,x,y;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        int maxt=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            a[y][x]++;
            if(y>maxt) maxt=y;
        }
        for(int i=maxt-1;i>=0;i--)
        {
            a[i][0]+=max(a[i+1][0],a[i+1][1]);
            a[i][10]+=max(a[i+1][10],a[i+1][9]);
            for(int j=1;j<=9;j++)
                a[i][j]+=max(max(a[i+1][j-1],a[i+1][j]),a[i+1][j+1]);
        }
        cout<<a[0][5]<<endl;
    }
    return 0;
}
