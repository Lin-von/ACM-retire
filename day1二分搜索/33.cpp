#include"stdio.h"
#include"iostream"

using namespace std;
int a[50005],b[50005];
int i,n,m,l,r,k,ans=0;




int main()
{
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    scanf("%lld",&m);
    //for(i=0;i<m;i++) scanf("%lld",&b[i]);

    l=0; r=0;
    while(m--)
    {
        scanf("%lld",&k);
        if(a[l]+k==10000) {ans=1; break;}
        while (a[l]+k<10000) l++;
    }
    if(ans==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
