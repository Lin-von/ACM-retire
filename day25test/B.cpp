#include"iostream"
#include"string.h"
#include"algorithm"
using namespace std;
int a[100000+5];
int main()
{
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cin>>q;
    int x;
    while(q--)
    {
        cin>>x;
        cout<<upper_bound(a,a+n,x)-a<<endl;;
    }
    return 0;
}
