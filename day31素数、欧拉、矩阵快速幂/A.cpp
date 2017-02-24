#include"iostream"
#include"cmath"
using namespace std;
int euler(int n)
{
    int m=(int)sqrt(n+0.5);
    int ans=n;
    for(int i=2;i<=m;i++)
        if(n%i==0)
    {
        ans=ans/i*(i-1);
        while(n%i==0) n/=i;
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n;
        int sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            sum+=euler(i);
        }
        cout<<cas++<<' '<<n<<' '<<sum*2+1<<endl;
    }
    return 0;
}
