#include"iostream"
#include"string"
#include"string.h"
using namespace std;
long long  k[100000+10];
string s;
long long max(long long a,long long b)
{
    return a>b?a:b;
}
int main()
{
    int t;
    cin>>t;

    for(int w=1;w<=t;w++)
    {
        cin>>s;
        int l=s.length();
        int cnt=1;
        long long sum=0;
        memset(k,0,sizeof(k));
        k[cnt]=1;
        for(int i=1;i<l;i++)
        {
            if(s[i]!=s[i-1]) cnt++;
            k[cnt]++;
        }
        for(int i=1;i<=cnt;i++)
       // cout<<k[i]<<endl;
             sum+=k[i]*k[i];
       // cout<<k[1]<<k[2]<<endl;
      /*  if(x==1)
        {
            cout<<"Case #"<<w<<": "<<sum<<endl;
            continue;
        }*/
       // cout<<x<<endl;
        long long maxx=sum;
        //k[0]=0; k[x]=0;
        for(int i=1;i<=cnt;i++)
        {
            long long  x,y,z;
            x=k[i-1];
            y=k[i];
            z=k[i+1];
            if(k[i]==1)
                maxx=max(sum-x*x-y*y-z*z+(x+y+z)*(x+y+z),maxx);
                else
                {
                    maxx=max(sum-x*x-y*y+(y-1)*(y-1)+(x+1)*(x+1),maxx);
                    maxx=max(sum-z*z-y*y+(y-1)*(y-1)+(z+1)*(z+1),maxx);
                }
        }

       /* for(int i=1;i<x;i++)
        {
            if(k[i]==1)
            {
                //cout<<666<<endl;
                long long temp=1;
                long long sum1=sum;
                sum1-=1;
                 if(i>1)
                {
                    sum1-=k[i-1]*k[i-1];
                    temp+=k[i-1];
                }
                if(i<x-1)
                {
                    sum1-=k[i+1]*k[i+1];
                    temp+=k[i+1];
                }
                sum1+=temp*temp;
                if(sum1>maxx) maxx=sum1;


            }
            else
            {
                if(i>1)
                {
                    long long sum1=sum;
                    int x=k[i-1]; int y=k[i];
                    sum1-=x*x;
                    sum1-=y*y;
                    sum1+=(x+1)*(x+1); //cout<<sum1<<endl;
                    sum1+=(y-1)*(y-1); //cout<<sum1<<endl;
                    if(sum1>maxx) maxx=sum1;
                }
                if(i<x-1)
                {
                    long long sum1=sum;
                    int x=k[i+1]; int y=k[i];
                    sum1-=x*x;
                    sum1-=y*y;
                    sum1+=(x+1)*(x+1);
                    sum1+=(y-1)*(y-1);
                    if(sum1>maxx) maxx=sum1;
                }
            }

        }*/
        cout<<"Case #"<<w<<": "<<maxx<<endl;


    }

    return 0;
}
