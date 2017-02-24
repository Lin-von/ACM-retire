#include"iostream"
#include"string.h"
using namespace std;
int main()
{
    int n,u,d;
    while(cin>>n>>u>>d)
    {
        if(n==0) break;
        int temp;
        temp=(n-u)/(u-d);
        if(temp*(u-d)<(n-u)) temp++;
        temp*=2;
        temp++;
        cout<<temp<<endl;
    }
    return 0;
}
