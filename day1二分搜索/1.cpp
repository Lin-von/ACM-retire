#include"iostream"
#include"algorithm"
using namespace std;
int l,m,n,s,ans,x,k;
int t=1;
int a[505],b[505],c[505],d[505*505];
int find(int x)
{
    int l,r,mid;
    l=0; r=k;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(d[mid]==x) return 1;
        else if(d[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return 0;
}
int main()
{
    while(cin>>l>>n>>m)
    {
        for(int i=0;i<l;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<m;i++) cin>>c[i];
        cin>>s;
        cout<<"Case "<<t++<<":"<<endl;
        k=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            d[k++]=b[i]+c[j];
        sort(d,d+k);

        while(s--)
        {
            ans=0;
            cin>>x;
            for(int i=0;i<l;i++)
                if(find(x-a[i]))
            {
                ans=1;
                break;
            }
            if(ans==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
