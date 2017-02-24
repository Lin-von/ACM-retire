#include"iostream"
#include"string.h"
#include"queue"
using namespace std;
queue<int > q;
int a[8],b[8];
int main()
{
    a[1]=1;
    for(int i=2;i<=7;i++) a[i]=a[i-1]*10;
    int n;
    while(cin>>n)
    {
        int sum=0;
        for(int i=7;i>=1;i--)
            {
                b[i]=n/a[i];
                if(b[i]!=0) n%=a[i];
            }
       /* for(int i=1;i<=7;i++)
        cout<<b[i]<<endl;*/
        int p=7;
        while(p>=1)
        {
            while(b[p]>0)
            {
                int temp=1e8;
                int ans;
                for(int i=p;i>=1;i--)
                {
                    if(b[i]!=0&&b[i]<temp) {temp=b[i]; ans=i;}
                }
                int k=0;
                for(int i=p;i>=1;i--)
                {
                    if(b[i]!=0)
                    {
                        sum+=temp;
                        b[i]-=temp;
                        k+=a[i];
                    }
                }
                for(int i=0;i<temp;i++) q.push(k);
            }
            p--;
        }
        cout<<q.size()<<endl;
        while(!q.empty()) {cout<<q.front()<<' '; q.pop();}
        cout<<endl;


    }
    return 0;
}
