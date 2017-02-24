#include"iostream"

#include"cmath"
#include"iomanip"
using namespace std;

int main()
{
    double l,n,c;
    while(cin>>l>>n>>c)
    {
        if(l==-1) break;

        double s=(1+n*c)*l;
        double lo,hi,mid;
        lo=0; hi=l/2;
        while(hi-lo>0.0001)
        {
            mid=(lo+hi)/2.0;
            double ts;
            double r;
            r=(4*mid*mid+l*l)/(8*mid);
            ts=2*r*asin(l/(2*r));
            if(ts<s) lo=mid;
            else hi=mid;


        }
        cout<<fixed<<setprecision(3)<<hi<<endl;
    }
    return 0;
}
