#include"iostream"
#include"string.h"
using namespace std;
int a[2000+5];
int main()
{
    int n;
    while(cin>>n)
    {
        int maxx=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            int temp=i;
            int cnt=1;
            while(a[temp]!=-1)
            {
                temp=a[temp];
                cnt++;

            }
            if(cnt>maxx) maxx=cnt;
        }
        cout<<maxx<<endl;
    }

}
