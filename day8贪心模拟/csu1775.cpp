#include"iostream"
#include"algorithm"
using namespace std;
int a[100000+5];
int n,len,sum;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        cin>>len;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int l,r;
        l=0; r=n-1;
        while(l<r)
        {
            if(a[l]+a[r]>len) r--;
            else { l++; r--; }
            sum++;
        }
        if(l==r) sum++;
        cout<<sum<<endl;
        cout<<endl;
    }
    return 0;
}
