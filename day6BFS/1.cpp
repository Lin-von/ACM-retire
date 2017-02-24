#include"iostream"
#include"queue"
using namespace std;
queue<int>q;

int sum=1;
int m,n,x,y;
char g[25][25];
int v[25][25];
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
        q.pop();
        int cx,cy;
        cx=w/m;
        cy=w%m;
        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]=='.'&&!v[nx][ny])
                {
                 //cout<<nx<<ny<<endl;
                 v[nx][ny]=1;
                 q.push(nx*m+ny);
                 sum++;
                }
        }
    }
}
int main()
{
    while(cin>>m>>n)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>g[i][j];
                v[i][j]=0;
                if(g[i][j]=='@') {x=i; y=j; v[i][j]=1;}
            }
            //cout<<x<<y<<endl;
         BFS(x,y);
         cout<<sum<<endl;
    }
    return 0;
}
