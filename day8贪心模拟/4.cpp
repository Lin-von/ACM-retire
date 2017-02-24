#include"iostream"
#include"algorithm"
#include"string.h"
#include"memory.h"
using namespace std;
struct node{
  int x,y;
};
int cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x>b.x;
}
node tas[100005],mac[100005];
int yi[100+5];
int n,m;
int main()
{
    while(cin>>n>>m)
    {

        long long sum=0,cnt=0;
        memset(yi,0,sizeof(yi));
        for(int i=0;i<n;i++) cin>>mac[i].x>>mac[i].y;
        for(int i=0;i<m;i++) cin>>tas[i].x>>tas[i].y;

        sort(tas,tas+m,cmp);
        sort(mac,mac+n,cmp);
        int k=0;
        for(int i=0;i<m;i++)
        {
            while(k<n&&mac[k].x>=tas[i].x)
            {
                yi[mac[k].y]++;
                k++;
            }
            int w=tas[i].y;
            while(!yi[w]&&w<=100) w++;
            if(w<=100)
            {
                yi[w]--;
                cnt++;
                sum+=500*tas[i].x+2*tas[i].y;
            }





        }
        cout<<cnt<<' '<<sum<<endl;
    }
    return 0;
}
