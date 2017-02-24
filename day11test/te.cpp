#include"iostream"
#include"stdio.h"
#include"string.h"
#include"queue"
using namespace std;

 int T;
int sum=1;
int eflag;
int m,n,x,y;
int ex,ey;
char g[2][12][12];
int v[2][12][12];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct node{
    int x, y, z;
    int step;
     bool operator == (const node& rhs) const {
        return z == rhs.z && x == rhs.x && y == rhs.y;
    }
    node(int z=0, int x=0, int y=0):z(z),x(x),y(y) {}
};

node S,P;

bool bfs(node S) {
    queue<node> q;
    memset(v,-1,sizeof(v));
    v[S.z][S.x][S.y] = 0;
    q.push(S);
    while(!q.empty()) {
        node w = q.front(); q.pop();
        if(w == P&& v[w.z][w.x][w.y] <= T) return true;
        for(int i=0;i<4;i++) {
            int z = w.z, x = w.x + dx[i], y = w.y + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(g[z][x][y] == '#') z = 1 - z;

            if(g[z][x][y] == '#' && g[1-z][x][y] == '#') continue;
            if(v[z][x][y] == -1 && g[z][x][y] != '*') {
                   v[z][x][y] = v[w.z][w.x][w.y] + 1;
                q.push(node(z,x,y));
            }
        }
    }
    return false;
}
int main()
{

  freopen("F:\\in.txt", "r", stdin);
  freopen("F:\\out.txt", "w", stdout);
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n>>m>>T;
       for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				cin>>g[0][i][j];
				if(g[0][i][j]=='S')
				{
					S.x=i;
					S.y=j;
					S.z=0;
					S.step=0;
				}
				else if(g[0][i][j]=='P')
				{
					P.x=i;
					P.y=j;
					P.z=0;
					P.step=0;
				}
			}
		}
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				cin>>g[1][i][j];
				if(g[1][i][j]=='S')
				{
					S.x=i;
					S.y=j;
					S.z=1;
					S.step=0;
				}
				else if(g[1][i][j]=='P')
				{
					P.x=i;
					P.y=j;
					P.z=1;
					P.step=0;
				}
			}
		}

           // v[0][0][0]=0;

         if(bfs(S)) printf("YES\n");
        else printf("NO\n");
        // cout<<sum<<endl;
    }
    return 0;
}
