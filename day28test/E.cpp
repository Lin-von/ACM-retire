#include"iostream"
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long  x=1;
    int cnt=0;
    while((x+1)*x/2*3-x<=n)
    {
        if((n-(x+1)*x/2*3+x)%3==0)  cnt++;
        x++;
    }
    cout<<cnt<<endl;

    return 0;
}
