#include"iostream"
#include"queue"
using namespace std;
queue<int>q;
int l;
int sum=0;
int m,n,x,y,sx,sy,ex,ey;
int g[310][310];
int v[310][310];
int dx[8]={-2,-1,1,2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

int BFS(int x,int y)
{


    while(!q.empty()) q.pop();
    q.push(x*l+y);
    while(!q.empty())
    {

        int w=q.front();
        //cout<<w<<endl;
        //cout<<endl;
        q.pop();
        int cx,cy;
        cx=w/l;
        cy=w%l;
        for(int i=0;i<8;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx==ex&&ny==ey) return g[cx][cy]+1;
            else if(nx>=0&&nx<l&&ny>=0&&ny<l&&v[nx][ny]==0)
                {
                 //cout<<nx<<ny<<endl;
                 g[nx][ny]=g[cx][cy]+1;
                 v[nx][ny]=1;
                 q.push(nx*l+ny);

                }
        }
        //sum++;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>l;
        for(int i=0;i<l;i++)
            for(int j=0;j<l;j++)
            v[i][j]=0;
        cin>>sx>>sy;
        g[sx][sy]=0;
        cin>>ex>>ey;
        if(sx==ex&&sy==ey) cout<<0<<endl;
        else cout<<BFS(sx,sy)<<endl;
    }
    return 0;
}
