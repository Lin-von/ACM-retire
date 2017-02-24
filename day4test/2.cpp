#include"iostream"
using namespace std;
int f(int n)
{
    return((n&(n-1))==0);
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(f(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

