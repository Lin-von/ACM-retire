#include"iostream"
using namespace std;
int a[1005],f[1005];
int main()
{
    int n,maxx=-1;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    f[0]=0;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++) if(a[i]>a[j]&&f[i]<f[j]) f[i]=f[j];
            f[i]++;
        }
    for(int i=0;i<n;i++) if(f[i]>maxx) maxx=f[i];
    cout<<maxx<<endl;

    return 0;

}
