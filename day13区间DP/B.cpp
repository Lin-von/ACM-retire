#include"iostream"
#include"string.h"
#include"string"
#include"iomanip"
using namespace std;
char a[100+5];
string s;
int dp[100+5][100+5];
int sum[100+5][100+5];
int max(int a,int b)
{

    return a>b?a:b;
}
int test(int i,int j)
{
    if(s[i-1]=='('&&s[j-1]==')') return 1;
    if(s[i-1]=='['&&s[j-1]==']') return 1;
    return 0;
}
int main()
{
    while(cin>>s)
    {
        if(s=="end") break;
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        int len=s.length();
        for(int i=1;i<s.length();i++)
            if(test(i,i+1)) dp[i][i+1]=2;


        for(int l=3;l<=len;l++)
            for(int i=1;i<=len-l+1;i++)
        {
            int j=i+l-1;
            if(test(i,j)) dp[i][j]=dp[i+1][j-1]+2;
            for(int k=i;k<j;k++) dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
        }

        cout<<dp[1][len]<<endl;
    }
    return 0;
}
