#include"iostream"
#include"cmath"
#include"iomanip"
int n;
const double PI=3.1415926535898;
struct node{
    double x,y;
};
node p[33],q[33];

double s(double rad)
{
    for(int i=0;i<n;i++)
    {
        q[i].x=p[i].x*cos(rad)-p[i].y*sin(rad);
        q[i].y=p[i].x*sin(rad)+p[i].y*cos(rad);

        //cout<<q[i].x<<' '<<q[i].y<<endl;
        //cout<<endl;
    }

    double minx=10000,miny=10000,maxx=-10000,maxy=-10000;
    for(int i=0;i<n;i++)
    {
       if(q[i].x<minx) minx=q[i].x;
       if(q[i].x>maxx) maxx=q[i].x;
       if(q[i].y<miny) miny=q[i].y;
       if(q[i].y>maxy) maxy=q[i].y;
    }
    return (maxx-minx)>(maxy-miny)?(maxx-minx)*(maxx-minx):(maxy-miny)*(maxy-miny);
}

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //cout<<cos(PI)<<endl;
        cin>>n;
        for(int i=0;i<n;i++) { cin>>p[i].x>>p[i].y;  }
        //for(int i=0;i<n;i++) { cout<<p[i].x<<p[i].y<<endl;  }
        double l,r,midl,midr,s1,s2;
        l=0; r=PI;
        //cout<<s(0)<<endl;
        while(r-l>0.0000000001)
        {
            midl=(l+r)/2.0;
            midr=(midl+r)/2.0;
            s1=s(midl); // for(int i=0;i<n;i++) { cout<<q[i].x<<q[i].y<<endl;  } cout<<s1<<' ';
            s2=s(midr); // for(int i=0;i<n;i++) { cout<<q[i].x<<q[i].y<<endl;  } cout<<s2<<' ';
            if(s1<s2) r=midr;
            else l=midl;
           // cout<<l<<' '<<r<<endl;
        }
        cout<<fixed<<setprecision(2)<<s(l)<<endl;

    }
}
