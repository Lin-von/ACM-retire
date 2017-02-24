#include"iostream"
using namespace std;
long long n,x,temp;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        x=0;
        temp=1;
        cin>>n;
        while(x<n) {x+=temp; temp++;}
        x-=temp-1;
        n-=x;

        if(n%9==0 )cout<<9<<endl;
        else cout<<n%9<<endl;
    }
    return 0;
}
