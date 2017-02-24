#include<stdio.h>
#include"iostream"
#include"cmath"
#include"algorithm"
#include"vector"
using namespace std;
int a[100000+5];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
   // cout<<gcd(27,9)<<endl;
    int x,y,n,l,r;
    cin>>x>>y;
    a[0]=gcd(x,y);
    int p=1;
    int w=sqrt(a[0]);
    for(int i=1;i<=w;i++)
        if(a[0]%i==0)
        {
            a[p++]=i;
            a[p++]=a[0]/i;
        }
    sort(a,a+p);
    // for(int i=0;i<p;i++) cout<<a[i]<<endl;
    cin>>n;
    while(n--)
    {

        cin>>l>>r;
        int loc=upper_bound(a,a+p,r)-a;
        //cout<<loc<<endl;
        int k=a[loc-1];
        if(k>=l) cout<<k<<endl;
        else cout<<-1<<endl;


    }
   // cout<<gcd(16,24)<<endl;
    return 0;
}
