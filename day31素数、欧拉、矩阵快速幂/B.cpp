#include"iostream"
#include"cmath"
#include"string.h"
using namespace std;
int phi[1000000+10];


int main()
{

    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(int i=2;i<=1000000+10;i++)
        if(!phi[i])
        for(int j=i;j<=1000000+10;j+=i)
    {
        if(!phi[j]) phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
    }

    int n;
    while(cin>>n&&n)
    {
        long long sum=0;

        for(int i=2;i<=n;i++)
        {
            sum+=phi[i];
        }
        cout<<sum<<endl;
    }


    return 0;
}
