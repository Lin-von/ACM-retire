#include"iostream"
#include"cmath"
#include<cstdlib>
#include"algorithm"
#include"string"
using namespace std;

int num[4],flag=0;
void dfs(int x,int y,int t)

{
   if(flag) return;
   if(t==3) {
      if(x+y==24||x-y==24||x*y==24) flag=1;
      if(y!=0&&x%y==0&&x/y==24) flag=1;
      return;
       }
      dfs(x+y,num[t+1],t+1);
      dfs(x-y,num[t+1],t+1);
      dfs(x*y,num[t+1],t+1);
      if(y!=0&&x%y==0) dfs(x/y,num[t+1],t+1);
      dfs(x,y+num[t+1],t+1);
      dfs(x,y-num[t+1],t+1);
      dfs(x,y*num[t+1],t+1);
      if(num[t+1]!=0&&y%num[t+1]==0) dfs(x,y/num[t+1],t+1);
}
void charset(string s,int i)
{
    i--;
          if(s.length()>1) num[i]=10;
          else if(s=="A") num[i]=1;
          else if(s=="J") num[i]=11;
          else if(s=="Q") num[i]=12;
          else if(s=="K") num[i]=13;
          else if(s[0]<65) num[i]=s[0]-48;
}
int main()
{
    string s1,s2,s3,s4;
  while(cin>>s1>>s2>>s3>>s4)
  {
     charset(s1,1);
     charset(s2,2);
     charset(s3,3);
     charset(s4,4);
     flag=0;
     sort(num,num+4);
     do
        {
            dfs(num[0],num[1],1);
        }while(next_permutation(num,num+4)&&!flag);

      //for(int i=0;i<4;i++)    cout<<num[i]<<endl;
      if(flag)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
  }

}
