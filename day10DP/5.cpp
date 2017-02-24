#include"iostream"
#include"string"
#include"string.h"
//#include"memory.h"
using namespace std;
string s1,s2;
int f[1000][1000];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    while(cin>>s1>>s2)
    {
        memset(f,0,sizeof(f));

        for(int i=1;i<=s1.length();i++)
            for(int j=1;j<=s2.length();j++)
            if(s1[i-1]==s2[j-1]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);

        cout<<f[s1.length()][s2.length()]<<endl;
    }
    return 0;
}
