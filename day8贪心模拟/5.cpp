#include"iostream"
#include"algorithm"
using namespace std;
struct node{
    int w,s;
};
node a[100005];

int cmp(node a,node b)
{
    return a.w+a.s<b.w+b.s;
}
int main()
{   int n;
    while(cin>>n)
    {

        for(int i=0;i<n;i++) cin>>a[i].w>>a[i].s;

        sort(a,a+n,cmp);
        long long maxx=-1e9,sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum-a[i].s>maxx)  maxx=sum-a[i].s;
            sum+=a[i].w;
        }
        if(maxx<0) cout<<0<<endl;
        else cout<<maxx<<endl;
    }
    return 0;
}
