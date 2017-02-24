#include"iostream"
#include"string"
#include"string.h"
#include"stack"
using namespace std;
string s1,s2;
char ans[10000];
stack<char > s;
void dfs(int p1,int p2,int cnt)
{
    if(p2==s2.length())
    {

        for(int i=0;i<cnt;i++) cout<<ans[i]<<' ';
        cout<<endl;
        return;
    }
    if(p1<s1.length())
    {
       // char c=s[p1];
        s.push(s1[p1]);
        ans[cnt]='i';
        dfs(p1+1,p2,cnt+1);
        s.pop();
    }
    if(p2<s2.length()&&!s.empty())
        if(s2[p2]==s.top())
    {
        s.pop();
        ans[cnt]='o';
        dfs(p1,p2+1,cnt+1);
        s.push(s2[p2]);
    }


}

int main()
{
    while(cin>>s1>>s2)
    {
        cout<<'['<<endl;
        while(!s.empty()) s.pop();
        if(s1.length()==s2.length())
        dfs(0,0,0);
        cout<<']'<<endl;
    }

    return 0;
}
