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
node tas[1005];
int v[100000+5];

int n,m;
int main()
{
    int  t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long sum=0,cnt=0;
        memset(v,0,sizeof(v));

        for(int i=0;i<n;i++) { cin>>tas[i].x;  }
        for(int i=0;i<n;i++) { cin>>tas[i].y;  sum+=tas[i].y;}

        sort(tas,tas+n,cmp);
  //cout<<sum<<endl;
        //  for(int i=0;i<n;i++) { cout<<tas[i].x<<' '<<tas[i].y<<endl;  }
        int w=tas[0].x;
        while(w)
        {
            int k=0;
            int maxx=-1;
            int flag=-1;
            while(k<n&&tas[k].x>=w)
            {
                //cout<<k<<' '<<tas[k].x<<' '<<w<<endl;
                if(tas[k].y>maxx&&!v[k]) {maxx=tas[k].y; flag=k;}
                k++;
            }
           // cout<<flag<<endl;
            if(flag!=-1) { sum-=maxx; v[flag]=1;}
            w--;
        }




        cout<<sum<<endl;
    }
    return 0;
}
