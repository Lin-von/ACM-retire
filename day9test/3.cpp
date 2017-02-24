#include"iostream"
#include"stdio.h"
#include"memory.h"
#include"string.h"

using namespace std;
int x[200005],y[200005];
int p[2000],q[2000];


int main()
{
    int n;
    while(cin>>n)
    {
        //cout<<calc(18)<<endl;
        //cout<<calc(3)<<endl;
        int sum=0;
        memset(p,0,sizeof(p));
        memset(q,0,sizeof(q));
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
            p[y[i]-x[i]+1000]++;  //cout<<y[i]-x[i]+1000<<endl;
            q[y[i]+x[i]]++;   //cout<<y[i]-(1000-x[i]+1)+1000<<endl;

        }

        for(int i=0;i<2000;i++)
        {
            sum+=p[i]*(p[i]-1)/2;
            sum+=q[i]*(q[i]-1)/2;
        }
        cout<<sum<<endl;
    }


    return 0;
}
