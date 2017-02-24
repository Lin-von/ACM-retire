#include"iostream"
using namespace std;

long long qp(long long n,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1) ans=ans*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ans;
}
int main(){
    int t,n,m,h,k;
    long long sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>m;
        cin>>h;

        while(h--)
        {
            cin>>n>>k;
            sum+=qp(n,k,m);

        }
        cout<<sum%m<<endl;

    }



return 0;
}
