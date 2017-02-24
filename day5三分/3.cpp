#include"iostream"
#include"iomanip"
#include"math.h"
using namespace std;
const double PI=3.141592653589793;

double R,r,H,v;
double V(double r1,double r2,double h)
{
    return (r1*r1+r2*r2+r2*r1)*PI*h/3;
}
double sr(double h)
{
    return (R-r)*h/H+r;
}

double find(double v)
{
    double lo,hi,mid,k;
    lo=0; hi=100;

    while(lo+0.00000001<hi)
    {

        mid=(lo+hi)/2.0;
        k=V(r,sr(mid),mid);

        if(fabs(k-v)>0.00000001)
        {
            if(k>v)hi=mid-0.00000001;
            else   lo=mid+0.00000001;

        }
        else break;
    }
    return mid;
}
int main()
{
    int t;

    double y,k;
    cin>>t;
    while(t--)
    {
        cin>>r>>R>>H>>v;



           cout<<fixed<<setprecision(6)<<find(v)<<endl;

    }


    return 0;
}
