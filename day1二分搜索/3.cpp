#include"stdio.h"
#include"iostream"

using namespace std;
int a[50005],b[50005];
int i,n,m,k;
int flag=0;
void find(int x)
{
 int l,r,mid;
 l=0; r=n-1;

 while(l<=r)
 {
  mid=(l+r)/2;
  if(a[mid]==x) {flag=1; return;}
  else if(a[mid]<x) l=mid+1;
  else r=mid-1;
 }

}


int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&k);
        find(10000-k);

    }


   if(flag==1) printf("YES\n");
    else printf("NO\n");

    return 0;
}
