#include"iostream"
#include"iomanip"
using namespace std;
const double PI=3.14159265358979;
int t,n,f,sum;
double maxx;
double s[10005];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>f;
        maxx=0;
        for(int i=0;i<n;i++) { cin>>s[i];  s[i]=s[i]*s[i]; maxx+=s[i]; }
        f++;
        double l,r,mid;
        l=0; r=maxx/f;
        while((r-l)>0.000001)
        {
            mid=(l+r)/2.0;
            sum=0;
            for(int i=0;i<n;i++) sum+=(int)(s[i]/mid);
            if(sum>=f) l=mid;
            else r=mid;

        }
        //cout<<mid<<endl;
        cout<<fixed<<setprecision(4)<<mid*PI<<endl;
    }
    return 0;
}
