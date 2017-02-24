#include"iostream"
#include"string.h"
#include"map"
using namespace std;
int n;
int a[100000+10];
long long sum;
int main()
{

    while(cin>>n)
    {
        sum = 0;
        for(int i=1;i<=n;i++) cin>>a[i];
        map <long long, int> m;
        m[0]=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            sum+=a[i];
            m[sum]++;
            if(m[sum]>ans) ans=m[sum];
        }
        cout<<n-ans<<endl;
    }
    return 0;
}
