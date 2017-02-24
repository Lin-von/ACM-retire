#include"iostream"
#include"queue"
#include"cmath"
using namespace std;
queue<int>q;
int n;
int a[200000+5];
int v[200000+5];




void BFS()
{


    while(!q.empty()) q.pop();
    q.push(1);
    while(!q.empty())
    {
       int x=q.front();
       q.pop();
       int y=x-1;
       if(y>0&&y<=n&&v[y]==-1)
       {
           v[y]=v[x]+1;
           q.push(y);
       }
       y=x+1;
       if(y>0&&y<=n&&v[y]==-1)
       {
           v[y]=v[x]+1;
           q.push(y);
       }
       y=a[x];
       if(y>0&&y<=n&&v[y]==-1)
       {
           v[y]=v[x]+1;
           q.push(y);
       }





    }
    cout<<0;
    for(int i=2;i<=n;i++)    cout<<" "<<v[i];
    cout<<endl;
}
int main()
{
    cin>>n;

    for(int i=1;i<=n;i++) {cin>>a[i]; v[i]=-1;}
    v[1]=0;
    BFS();



    return 0;
}
