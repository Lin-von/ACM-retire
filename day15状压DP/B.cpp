#include"iostream"
#include"string.h"
#include"cmath"
#include"string"
using namespace std;
int dp[100+5][1<<10+5];
int a[100+5];
int check(int i,int j)
{
    if((a[i]&j)!=j) return 0;
    if(j&(j<<1)!=0||j&(j<<2)!=0) return 0;
    return 1;
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
        {
            a[i]=0;
            cin>>s;
            int x;
            for(int j=0;j<n;j++)
                {
                    if(s[j]=='P') x=1; else x=0;
                    a[i]=(a[i]<<1)+x;
                }

            for(int i=1;i<=n;i++)
                for(int j=0;j<(1<<10);j++)

        }



    }
    return 0;
}
