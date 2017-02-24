#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;

int hashs[7003],cnt[7003];
int maxx;
char str[50];


 int ELFhash(char *key)
{
    unsigned long h = 0;
    unsigned long g;
    while( *key )
    {
        h =( h<< 4) + *key++;
        g = h & 0xf0000000L;
        if( g ) h ^= g >> 24;
        h &= ~g;
    }
    return h;
}

void make_hash(char *str)
{
    int k,t;
    while(*str=='0') str++;
    k=ELFhash(str);
    t=k%7003;
    while(hashs[t]!=k&&hashs[t]!=-1)
        t=(t+10)%7003;
    if(hashs[t]==-1)
    {
        cnt[t]=1;
        hashs[t]=k;
    }
    else if(++cnt[t]>maxx) maxx=cnt[t];
}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(hashs,-1,sizeof(hashs));
        maxx=1;
        while(n--)
        {
            scanf("%s",str);
            make_hash(str);
        }
        cout<<maxx<<endl;
    }
}
