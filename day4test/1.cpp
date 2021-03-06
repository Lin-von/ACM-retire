#include"iostream"
#include"memory.h"
#include"algorithm"
using namespace std;
int n;
struct node{
    int l,r;
};
node d[10005];
int v[10005];
int cmp(const node& a,const node& b)
{
    return (a.r<b.r)||(a.r==b.r&&a.l<b.l);
}

int test(int x)
{

    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=d[i].l+1;j<=d[i].r;j++)
        if(!v[j])
        {
            v[j]=1;
            sum++;
            if(sum==x) break;
        }
        if(sum<x) return 0;
    }
    return 1;
}

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i].l>>d[i].r;
    //for(int i=0;i<n;i++) cout<<d[i].l<<d[i].r<<endl;
    sort(d+1,d+n+1,cmp);
    //for(int i=0;i<n;i++) cout<<d[i].l<<d[i].r<<endl;
    int hi,lo,mid;
    lo=1;
    hi=10000+1;

    while(!test(hi)&&hi>0) hi--;

    if(test(hi)) cout<<hi*n<<endl;
    else cout<<0<<endl;

}
