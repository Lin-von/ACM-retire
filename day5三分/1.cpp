#include"iostream"
#include"iomanip"
#include"math.h"
using namespace std;
double F(double x,double y)
{
    return 6*x*x*x*x*x*x*x+8*x*x*x*x*x*x+7*x*x*x+5*x*x-y*x;
}

double find(double y)
{
    double l,r,mid,mmid,p,q;
    l=0; r=100;

    while(l+0.00001<r)
    {

        mid=(l+r)/2.0;
        mmid=(mid+r)/2.0;

        p=F(mid,y);
        q=F(mmid,y);


        if(p<q)r=mmid;
        else   l=mid;



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



           cout<<fixed<<setprecision(4)<<F(find(y),y)<<endl;

    }


    return 0;
}
