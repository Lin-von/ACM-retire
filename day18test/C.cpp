#include"iostream"
#include"algorithm"
#include"string.h"
#include"iomanip"
using namespace std;
struct node{
  int x,p;
};
int cmp(node a,node b)
{
    return a.x<b.x;
}
node nd[15000+5];
int main()
{

    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>nd[i].x>>nd[i].p;
        sort(nd,nd+n,cmp);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            nd[i].p+=nd[i-1].p;

        }
        sum=nd[n-1].p;
        sum/=2;
        for(int i=0;i<n;i++)
        {
            if(nd[i].p>=sum)
            {
                cout<<fixed<<setprecision(5)<<nd[i].x<<endl;
                break;
            }
        }


    }
    return 0;
}
