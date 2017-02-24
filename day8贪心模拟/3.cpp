#include"iostream"
using namespace std;
long long n,m;
int main()
{
    cin>>n;
    long long p=1e9/1234567+1;
    long long q=1e9/123456+1;
    int flag=0;
    for(int i=0;i<=p;i++)
        for(int j=0;j<=q;j++)
        {
            m=n-i*1234567-j*123456;
            if(m<0) break;
            if(m%1234==0) flag=1;
        }
      if(flag==1) cout<<"YES"<<endl;
      else cout <<"NO"<<endl;
    return 0;
}
