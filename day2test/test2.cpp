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
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<qp(n,n,10)<<endl;
    }



return 0;
}
