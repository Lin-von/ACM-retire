#include"iostream"
#include"cmath"
#include"iomanip"
#include"stdio.h"
using namespace std;
double x[50005],w[50005];
int n;
double calc(double d)  //fabs pow 耗时高
{
    double sum=0;
    for(int i=0;i<n;i++)
    {
        double dis=x[i]-d;
        if(dis<0) dis=-dis;
        sum+=dis*dis*dis*w[i];
    }
     return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&x[i],&w[i]);  //cin  耗时高
        double l,r,midl,midr,v1,v2;
        l=x[0]; r=x[n-1];
        while(r-l>0.00001)
        {
            midl=(l+r)/2.0;
            midr=(midl+r)/2.0;
            v1=calc(midl);
            v2=calc(midr);
            for(int i=0;i<n;i++)

            if(v1<v2) r=midr;
            else l=midl;
        }
        cout<<"Case #"<<k<<": ";
        if(v1<v2)
        cout<<fixed<<setprecision(0)<<v1<<endl;
        else cout<<fixed<<setprecision(0)<<v2<<endl;
    }

    return 0;
}
