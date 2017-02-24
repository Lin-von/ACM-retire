#include"iostream"
#include"string.h"
using namespace std;
int a[100000+5];
int main()
{
    int t;
    int cnt=1;
    cin>>t;
    t--;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int maxx=-1e8;
        int sum=-1;
        int maxl,maxr;
        int l,r;
        for(int i=1;i<=n;i++)
        {
            if(sum>=0)   {sum+=a[i]; r++;}
            else   { sum=a[i]; l=i; r=l;}


            if(sum>maxx) { maxx=sum; maxl=l; maxr=r;}

        }
        //int temp=maxx;
       // int tempp=maxp;
        //int ans=-1;
        //while(tempp>0) { temp-=a[tempp--]; if(temp==0) ans=tempp+1; }
        cout<<"Case "<<cnt++<<":"<<endl;
        cout<<maxx<<' '<<maxl<<' '<<maxr<<endl;
        cout<<endl;
    }
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int maxx=-1e8;
        int sum=-1;
        int maxl,maxr;
        int l,r;
        for(int i=1;i<=n;i++)
        {
            if(sum>=0)   {sum+=a[i]; r++;}
            else   { sum=a[i]; l=i; r=l;}


            if(sum>maxx) { maxx=sum; maxl=l; maxr=r;}

        }
        //int temp=maxx;
       // int tempp=maxp;
        //int ans=-1;
        //while(tempp>0) { temp-=a[tempp--]; if(temp==0) ans=tempp+1; }
        cout<<"Case "<<cnt++<<":"<<endl;
        cout<<maxx<<' '<<maxl<<' '<<maxr<<endl;


    return 0;
}
