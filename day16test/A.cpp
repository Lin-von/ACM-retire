#include<stdio.h>
#include"iostream"
#include"cmath"
#include"algorithm"
#include"iomanip"
#include"string.h"
#include"vector"
using namespace std;
double dp[100000+5];

double dfs(int x)
{
  // cout<<1<<endl;
   if(dp[x]!=-1) return dp[x];
   double sum=0;

   int p=2;
   //cout<<666<<endl;

    int w=sqrt(x);
    for(int i=2;i<=w;i++)
        if(x%i==0)
        {
            sum+=dfs(x/i); p++;
            if(x/i!=i) {sum+=dfs(i); p++;}
        }

   sum+=p;
   sum/=(p-1);
   //cout<<sum<<endl;
   dp[x]=sum;



    return dp[x];
}

int main()
{
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {

        int x;
        cin>>x;
        for(int i=0;i<=x;i++) dp[i]=-1;
        dp[1]=0;
        //cout<<1<<endl;
        cout<<"Case "<<cas++<<": ";
        cout<<fixed<<setprecision(12)<<dfs(x)<<endl;
    }
    return 0;
}
