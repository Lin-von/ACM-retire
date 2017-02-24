#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;


int a[1000000+5],b[10000+5];
int fail[10000+5],n,m;

void make_next()
{
    int i = 0,j = -1;
    fail[0] = -1;
    while(i<m)
    {
        if(j==-1||b[i]==b[j])
        {
            i++;
            j++;
            if(b[i]==b[j])
            fail[i]=fail[j];
            else
            fail[i]=j;
        }
        else
        j=fail[j];
    }
}

int kmp()
{
    int i = 0,j = 0;
    while(i<n)
    {
        if(a[i] == b[j])
        {
            if(j==m-1)
            return i-j+1;
            i++;
            j++;
        }
        else
        {
            j = fail[j];
            if(j == -1)
            {
                i++;
                j = 0;
            }
        }
    }
    return -1;
}

int main()
{
    int t,i;

    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<m;i++)
        scanf("%d",&b[i]);
        if(n<m)
        printf("-1\n");
        else
        {
            make_next();
            printf("%d\n",kmp());
        }
    }

    return 0;
}


