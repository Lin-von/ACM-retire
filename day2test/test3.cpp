#include"iostream"
#include"iomanip"
#include"math.h"
using namespace std;
double f(double x)
{
    return 42*x*x*x*x*x*x+48*x*x*x*x*x+21*x*x+10*x;
}
double F(double x,double y)
{
    return 6*x*x*x*x*x*x*x+8*x*x*x*x*x*x+7*x*x*x+5*x*x-y*x;
}
double find(double y)
{
    double l,r,mid,k;
    l=0; r=100;

    while(l+0.00001<r)
    {

        mid=(l+r)/2.0;
        k=f(mid);

        if(fabs(k-y)>0.00001)
        {
            if(k>y)r=mid;
            else   l=mid;

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
        cin>>y;
        if(f(100)<=y) cout<<fixed<<setprecision(4)<<F(100,y)<<endl;
        else
        {


           cout<<fixed<<setprecision(4)<<F(find(y),y)<<endl;
        }
    }


    return 0;
}
