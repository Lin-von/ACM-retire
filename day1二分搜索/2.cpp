#include"iostream"
#include"iomanip"
#include"math.h"
using namespace std;
double f(double x)
{
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}


double find(double y)
{
    double l,r,mid,k;
    l=0; r=100;
    mid=(l+r)/2.0;
    k=f(mid);
    while(fabs(k-y)>0.00001)
    {
       if(k>y)r=mid;
       else   l=mid;
       mid=(l+r)/2.0;
       k=f(mid);


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
        if(f(0)>y||f(100)<y) cout<<"No solution!"<<endl;
        else
        {


           cout<<fixed<<setprecision(4)<<find(y)<<endl;
        }
    }


    return 0;
}
