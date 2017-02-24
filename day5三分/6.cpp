#include"iostream"
#include"iomanip"
#include"cmath"
using namespace std;
const double PI=3.1415926535898;
double sh(double ra,double s)
{
    double len;
    len=(s/PI)/ra-ra;
    return sqrt(len*len-ra*ra);
}
int main()
{
    double s;
    while(cin>>s)
    {


    double l,r,mid,mmid,v1,v2;
    l=0; r=sqrt(s/(PI*2));
    while(r-l>0.00000001)
    {
        mid=(l+r)/2.0;
        mmid=(mid+r)/2.0;
        v1=PI*mid*mid*sh(mid,s)/3;
        v2=PI*mmid*mmid*sh(mmid,s)/3;
        if(v1>v2) r=mmid;
        else l=mid;

    }


    cout<<fixed<<setprecision(2)<<v1<<endl;
    cout<<fixed<<setprecision(2)<<sh(l,s)<<endl;
    cout<<fixed<<setprecision(2)<<l<<endl;
    }
    return 0;
}
