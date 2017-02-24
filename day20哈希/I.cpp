#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;
const int md=40000*5+3;
long long a[5+5][200+5];
long long hashs[md];
int v[md];
void make_hash(long long x)
{
    int k=x%md;
    if(k<0) k+=md;
    while(v[k]&&hashs[k]!=x)
        k=(k+1)%md;
    if(!v[k])
    {
        v[k]=1;
        hashs[k]=x;
    }

}

int judge(long long x)
{
    int k=x%md;
    if(k<0) k+=md;
    while(v[k]&&hashs[k]!=x)
        k=(k+1)%md;
    return k;
}

int main()
{
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        scanf("%d",&n);
        memset(v,0,sizeof(v));
        for(int i=0;i<5;i++)
            for(int j=0;j<n;j++)
               scanf("%I64d",&a[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                long long  w=-(a[0][i]+a[1][j]);
                make_hash(w);
            }
        int flag=0;
        for(int i=0;i<n&&!flag;i++)
           for(int j=0;j<n&&!flag;j++)
              for(int k=0;k<n&&!flag;k++)
              {
                  long long  w=a[2][i]+a[3][j]+a[4][k];
                  int h=judge(w);
                  if(v[h])
                  {
                      flag=1; break;
                  }
              }
        if(flag) printf("Yes\n");
        else printf("No\n");

    }
}
