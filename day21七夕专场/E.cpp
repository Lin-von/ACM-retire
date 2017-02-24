#include"iostream"
#include"string.h"
using namespace std;
int  row[100000+5];
int  clo[100000+5];

int main()
{
    long long n,m;
    while(cin>>n>>m)
    {
        long long sum=(long long )n*n;
        //cout<<sum<<endl;
        memset(row,0,sizeof(row));
        memset(clo,0,sizeof(clo));
        long long sumr,sumc;
        sumr=0;
        sumc=0;
        long long x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            if(!row[x]){
                sum -= n-sumc;
                row[x]=1;
                sumr++;
            }if(!clo[y]){
                sum -= n-sumr;
                clo[y] = 1;
                sumc++;
            }
            cout<<sum<<' ';
        }
        cout<<endl;

    }

    return 0;
}
