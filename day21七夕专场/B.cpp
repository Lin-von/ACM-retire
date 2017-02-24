#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;

int  main()
{
    int T,d,t,cnt=1;
    cin>>T;
    while(T--)
    {

        cin>>t>>d;
        cout<<"Case "<<cnt++<<": ";
        if(t%2==1)
        {
            cout<<0<<endl;
        }
        else
        {
            double k;
            k=(double)1/(t+1);
            cout<<fixed<<setprecision(10)<<k<<endl;
        }

    }
    return 0;
}
