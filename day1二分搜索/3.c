#include"stdio.h"
#include"iostream"
#include"algorithm"
using namespace std;
int a[100005],b[100005];
int i,n,m;
int flag=0;
void find(int x)
{
 int l,r,mid,k;
 l=0; r=m-1;
 k=10000-x;
 while(l<=r)
 {
  mid=((r-l)>>1)+l;
  if(b[mid]==k) {flag=1; return;}
  else if(b[mid]<k) l=mid+1;
  else r=mid-1;
 }

}


int main()
{
    scanf("%lld",&n);
    for(i=0;i<n;i++) {scanf("%lld",&a[i]); b[i]=a[i];}
    scanf("%lld",&m);
    for(i=n;i<m+n;i++) {scanf("%lld",&a[i]); b[i]=a[i];}
    sort(b,b+m+n);
    for(i=0;i<m+n;i++)
    {
        find(a[i]);
        if(flag==1)
        {
            printf("YES\n");
            break;

        }
    }
    if(flag==0) printf("NO\n");

    return 0;
}
