#include"iostream"
#include"string"
#include"queue"

using namespace std;


struct node{
  int les;
  string s;
};
queue<node> q;
int v[205];
node nd[205],w,d;

void BFS(int i)
{

    for(int j=0;j<205;j++) v[j]=0;
    while(!q.empty()) q.pop();
    w.s="1";
    w.les=1;
    q.push(w);
    v[1]=1;

    while(!q.empty())
    {
       w=q.front();
       d=w;
       q.pop();

       int x=(w.les*10+1)%i;
       int y=(w.les*10)%i;
       if(x==0) {nd[i].s=w.s+"1";  return;}
       if(y==0) {nd[i].s=w.s+"0";  return;}
       if(v[x]==0)
       {
           v[x]=1;
           w.s=w.s+"1";
           w.les=x;
           q.push(w);
       }
       if(v[y]==0)
       {
           v[y]=1;
           d.s=d.s+"1";
           d.les=y;
           q.push(d);
       }




    }

}

int main()
{
    int n;
    nd[1].s="1";
    for(int i=2;i<=200;i++)
        {
        if(i%2==0) nd[i].s=nd[i/2].s+"0";
        else BFS(i);
        }

cout<<nd[19].s<<endl;
    while(cin>>n);
    {
        //if(n==0) break;
        cout<<nd[n].s<<endl;
    }
}

/*#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct{
	int mod;
	string ans;
}Node;
Node node[210],temp,now;
bool dis[210];

void bfs(int i){
	int x,y;
	queue <Node>q;
	memset(dis,false,sizeof(dis));

	dis[1]=true;
	temp.ans="1";
	temp.mod=1;
	q.push(temp);

	while(!q.empty()){
		now=temp=q.front();
		q.pop();

		x=(temp.mod*10+1)%i;
		y=(temp.mod*10)%i;

		if(!x){
			node[i].ans=temp.ans+"1";
			return ;
		}
		if(!y){
			node[i].ans=temp.ans+"0";
			return ;
		}
		if(!dis[x]){
			temp.ans=temp.ans+"1";
			temp.mod=x;
			q.push(temp);
			dis[x]=true;
		}
		if(!dis[y]){
			now.ans=now.ans+"0";
			now.mod=y;
			q.push(now);
			dis[y]=true;
		}
	}
}

int main(){
	int i,n;
	node[1].ans="1";
	for(i=2;i<=200;i++){
		if(i%2==0) node[i].ans=node[i/2].ans+"0";
		else bfs(i);
	}
	while(scanf("%d",&n) && n){
		cout<<node[n].ans<<endl;
	}
	return 0;
}*/
