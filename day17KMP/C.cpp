#include"iostream"
#include"string.h"
#include"stdio.h"
using namespace std;
int next[1000000+5];
char s[1000000+5];
void make_next()
{
    int i=0,j=-1;
    next[0]=-1;
    int len=strlen(s);
    while(i<len)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
int main()
{
    while(scanf("%s",s)>0)
    {
        if(s[0]=='.')
            break;
        int len=strlen(s);
        make_next();
        if(len%(len-next[len])==0)
            printf("%d\n",len/(len-next[len]));
        else
            printf("1\n");
    }
    return 0;
}
