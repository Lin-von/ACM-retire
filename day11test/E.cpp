#include"iostream"
#include"stdio.h"
#include"string.h"
#include"queue"
using namespace std;
queue<int>q;
 int T;
int sum=1;
int eflag;
int m,n,x,y;
int ex,ey;
char g[12][12][2];
int v[12][12][2];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void BFS(int x,int y)
{
    sum=1;
    while(!q.empty()) q.pop();
    q.push(x*m+y);
    while(!q.empty())
    {
        int w=q.front();
        //cout<<w<<endl;
        int flag,flagn;
        q.pop();
        if(w<n*m) flag=0;
        else {flag=1; w-=n*m; }
        int cx,cy;
        cx=w/m;
        cy=w%m;
        if(g[cx][cy][flag]=='P'&&v[cx][cy][flag]<=T&&v[cx][cy][flag]!=-1) {cout<<"YES"<<endl; return;}
        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            flagn=flag;
            if(nx>=0&&nx<n&&ny>=0&&ny<m)
            {
                if(g[nx][ny][flagn]=='#') flagn=1-flagn;
                if(g[nx][ny][flagn]=='#'&&g[nx][ny][1-flagn]=='#') continue;
                if(v[nx][ny][flagn]==-1&&g[nx][ny][flagn]!='*')
                {
                    v[nx][ny][flagn]=v[cx][cy][flag]+1;
                    q.push(nx*m+ny+flagn*n*m);
                }
            }



        }
    }
    cout<<"NO"<<endl;
}
int main()
{

  //freopen("F:\\in.txt", "r", stdin);
  //freopen("F:\\out.txt", "w", stdout);
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n>>m>>T;
     for(int k=0;k<2;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)

            {
                cin>>g[i][j][k];
                v[i][j][k]=-1;
                if(g[i][j][k]=='P')  { ex=i; ey=j; eflag=k; }

            }

            v[0][0][0]=0;
         BFS(0,0);
        // cout<<sum<<endl;
    }
    return 0;
}
