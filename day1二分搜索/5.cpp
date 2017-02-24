#include"iostream"
#include"algorithm"
using namespace std;
int n,k,l,r,mid,mm,sum=0;
int a[4005],b[4005],c[4005],d[4005];
int p[4005*4005],q[4005*4005];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        p[k++]=a[i]+b[j];
    k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        q[k++]=c[i]+d[j];

    sort(q,q+k);

    for(int i=0;i<k;i++)
    {
        l=0; r=k-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(q[mid]==-p[i]) break;
            else if(q[mid]<-p[i]) l=mid+1;
            else r=mid-1;
        }
        if(q[mid]==-p[i])
        {
            mm=mid;
        while(q[mm]==-p[i]&&mm>=0) {sum++; mm--;}
        mm=mid;
        while(q[mm]==-p[i]&&mm<k) {sum++; mm++;}
        sum--;
        }

    }
    cout<<sum<<endl;
    return 0;
}
