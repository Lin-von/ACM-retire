#include"iostream"
#include"queue"
#include<vector>
using namespace std;
char g[220][220];
int vis[220][220];
int cos[220*220];
int n,m;
int sum;
int temp,cnt;
int flag;
int minsum;
int sx[40000],sy[40000];
int k[5000];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct cmp{
    bool operator ()(int &a,int &b){
        return cos[a]>cos[b];//最小值优先
    }
};
priority_queue<int ,vector<int >,cmp> q;

int bfs(int x,int y)
{
    //sum=1;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++) vis[i][j]=0;
      for(int i=0;i<=n*m;i++) cos[i]=0;
      vis[x][y]=1;
    while(!q.empty()) q.pop();
    q.push(x*m+y);
    while(!q.empty())
    {
        int w=q.top();
        //cout<<w<<endl;
        q.pop();
        int cx,cy;
        cx=w/m;
        cy=w%m;
        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(g[nx][ny]=='a') {flag=1;  return cos[cx*m+cy]+1;}
            else if(nx>=0&&nx<n&&ny>=0&&ny<m&&vis[nx][ny]==0&&g[nx][ny]=='.')
                {
                 //cout<<nx<<ny<<endl;

                 cos[nx*m+ny]=cos[cx*m+cy]+1;
                 vis[nx][ny]=1;
                 q.push(nx*m+ny);

                }
            else if(nx>=0&&nx<n&&ny>=0&&ny<m&&vis[nx][ny]==0&&g[nx][ny]=='x')
                {
                 //cout<<nx<<ny<<endl;

                 cos[nx*m+ny]=cos[cx*m+cy]+2;
                 vis[nx][ny]=1;
                 q.push(nx*m+ny);

                }
        }
    }

    return 0;
}
int main()
{

    while(cin>>n>>m)
    {
      minsum=1e8;
      cnt=0;
      flag=0;
      for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
          cin>>g[i][j];

          if(g[i][j]=='r') {sx[cnt]=i; sy[cnt]=j; cnt++;}
      }

      for(int i=0;i<cnt;i++)
      {
          temp=bfs(sx[i],sy[i]);
          if(temp>0) if(temp<minsum) minsum=temp;
      }
      if(flag!=0) cout<<minsum<<endl;
      else
      cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
    }




    return 0;
}
