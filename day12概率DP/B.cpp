#include"iostream"
#include"string.h"
#include"iomanip"
using namespace std;
double f[1000+5][1000+5];
int main()
{   int   n,s;
    while(cin>>n>>s)
    {
        memset(f,0,sizeof(f));
        for(int i=n;i>=0;i--)
            for(int j=s;j>=0;j--)
             {

               if(i==n&&j==s) continue;
              f[i][j]= (i*(s-j)*f[i][j+1]+(n-i)*j*f[i+1][j]+(n-i)*(s-j)*f[i+1][j+1]+n*s)/(n*s-i*j);//(i*j*(f[i][j]+1)+ i*(s-j)*(f[i][j+1]+1)+ (n-i)*j*(f[i+1][j]+1)+ (n-i)*(s-j)*(f[i+1][j+1]+1))/(n*s);
         }

       /* for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
                cout<<f[i][j]<<' ';
            cout<<endl;
        }*/
       cout<<fixed<<setprecision(4)<<f[0][0]<<endl;
    }

    return 0;
}
