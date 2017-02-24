#include"iostream"
#include"iomanip"
#include"cmath"
using namespace std;
const double PI=3.1415926535898;
const double g=9.8;
int t;
double x,y,v;
int main() {
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>v;
        double a=g*x*x,b=-2*v*v*x,c=2*v*v*y+g*x*x;
        double x1=(-b+sqrt(b*b-4*a*c))/2.0/a;
        double x2=(-b-sqrt(b*b-4*a*c))/2.0/a;
        x1=atan(x1);
        x2=atan(x2);
        if(x2>=0&&x2<=PI/2.0) cout<<fixed<<setprecision(6)<<x2<<endl;
        else if(x1>=0&&x1<=PI/2.0) cout<<fixed<<setprecision(6)<<x1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
