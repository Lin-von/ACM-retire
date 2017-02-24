#include"iostream"
#include"algorithm"
#include"stdio.h"
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}


int main()
{
    int t;

    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {

        int sum=1;
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        int k=gcd(x,y);
        while(y%(x+k)==0)
        {
            sum++;
            y=y/(x/k+1);
            if(x>y)
                swap(x,y);
            k=gcd(x,y);
        }
        printf("Case #%d: %d\n",cas,sum);
    }
    return 0;
}
