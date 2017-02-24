#include"iostream"
#include"string.h"
using namespace std;

int lowbit(int x)
{
    return x&(-x);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<x-lowbit(x)+1<<' '<<x+lowbit(x)-1<<endl;
    }
    return 0;
}
