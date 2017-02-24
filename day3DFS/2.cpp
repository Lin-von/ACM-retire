#include"iostream"
#include"cmath"
using namespace std;
int a[50],v[50];
int n;
int f(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return 0;
    return 1;
}

bool play(int k) {
    //cout<<endl;
    //cout<<"k:"<<k<<endl;
   if(k>n) { if(f(a[1]+a[n])) {for(int i=1;i<n;i++) cout<<a[i]<<' '; cout<<a[n]<<endl;} return false; }
   for(int i=2;i<=n;i++)
   {
     //cout<<"i:"<<i<<endl;
   if (!v[i]&&f(i+a[k-1]))
     {
        a[k]=i;   v[i]=1;
        if  (play(k+1))   return true;
       v[i]=0;      //½«iÈ¡³ö
     }//if
   }//for
     return false;
}//play

int main()
{
  int t=1;
    while(cin>>n)
    {
        cout<<"Case "<<t++<<":"<<endl;
        a[1]=1; a[1]=1;
        for(int i=2;i<=n;i++) {a[i]=0; v[i]=0;}
        play(2);
        cout<<endl;
    }

    return 0;

}
