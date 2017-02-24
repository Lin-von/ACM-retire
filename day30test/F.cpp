#include"iostream"
using namespace std;
int main()
{
    long long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long vis=0;
        long long sum=0;
        while(n)
        {
            if(n&1)
            {
                if(!vis) sum++;
                vis=1;

            }
            else vis=0;
            n/=2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
