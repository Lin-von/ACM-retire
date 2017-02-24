#include"iostream"
#include"cmath"
#include"string"
using namespace std;

double num[4];

int dfs(int n)
{
    for(int i=0;i<4;i++) if(num[i]!=(int)num[i]) return 0;
    if(n==1)
        {
         if(fabs(num[0]-24)<0.00001) { return 1; }
         else return 0;
        }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
    {
        double x,y;
        x=num[i];
        y=num[j];
        num[j]=num[n-1];
        num[i]=x+y; if(dfs(n-1)) return 1;
        num[i]=x-y; if(dfs(n-1)) return 1;
        num[i]=y-x; if(dfs(n-1)) return 1;
        num[i]=x*y; if(dfs(n-1)) return 1;
        if(x!=0) {num[i]=y/x; if(dfs(n-1)) return 1;}
        if(y!=0) {num[i]=x/y; if(dfs(n-1)) return 1;}
        num[i]=x;
        num[j]=y;
    }
    return 0;
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

     // for(int i=0;i<4;i++)    cout<<num[i]<<endl;
      if(dfs(4))cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
  }

}
