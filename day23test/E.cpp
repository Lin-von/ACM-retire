#include"iostream"
#include"string.h"
using namespace std;
int a[100+5];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(j%i==0) a[j]=1-a[j];
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
