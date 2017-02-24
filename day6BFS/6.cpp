#include"iostream"
#include"queue"
using namespace std;
queue<int>q;

int sum=0;
int m,n,x,y;
char g[110][110];
int v[110][110];
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};

void BFS(int x,int y)
{
    sum++;
    v[x][y]=sum;
    while(!q.empty()) q.pop();
    q.push(x*m+y);
    while(!q.empty())
    {

        int w=q.front();
        //cout<<w<<endl;
        //cout<<endl;
        q.pop();
        int cx,cy;
        cx=w/m;
        cy=w%m;
        for(int i=0;i<8;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]=='@'&&v[nx][ny]==0)
                {
                 //cout<<nx<<ny<<endl;
                 v[nx][ny]=sum;
                 q.push(nx*m+ny);

                }
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        sum=0;
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>g[i][j];
                v[i][j]=0;

            }
            //cout<<x<<y<<endl;
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(g[i][j]=='@'&&v[i][j]==0) BFS(i,j);
         cout<<sum<<endl;
    }
    return 0;
}
