#include"iostream"
#include"stdio.h"
using namespace std;
int l,r;
double v[100000+20];
long long v1[100000+5];
long long v2[100000+5];
int main()
{
    int n,p;
    double sum=0;
    long long temp;
    cin>>n>>p;

    for(int i=0;i<n;i++)
    {
        scanf("%d%d", &l, &r);
       // v1[i]=r/p-(l-1)/p;
       // v2[i]=r-l+1;
        //cout<<(r/p-(l-1)/p)<<endl;
       // cout<<(r-l+1)<<endl;
       temp=r/p-(l-1)/p;

        v[i]=(double)temp/(r-l+1);
        //cout<<v[i]<<endl;
    }
    v[n]=v[0];
    for(int i=0;i<n;i++)
    {
        //int j=(i+1)%n;
       // temp=v1[i]*v2[j]+v1[j]*v2[i]-v1[i]*v1[j];
        sum+=(v[i]+v[i+1]-v[i]*v[i+1])*2000.0;
       // cout<<temp<<endl;
        //sum+=temp;
        //cout<<sum<<endl;

    }
    printf("%lf\n",sum);  //cout???
    return 0;

}
