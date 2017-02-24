#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;

char s1[1000000+5],s2[1000000+5];
int fail[1000000+5];
int max(int a,int b)
{
    return a>b?a:b;
}
void get_next(char *s,int len)
{
    fail[0]=-1;
    int i=0,j=-1;
    while(i<len)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            fail[i] = j;
        }
        else j=fail[j];
    }
}
int kmp(char *t1,char *t2)
{
    int len1=strlen(t1);
    int len2=strlen(t2);
    get_next(t2,len2);
    int i=0,j=0;
    while(i<len1&&j<len2)
    {
        if(j==-1||t1[i]==t2[j])
        {
            i++;
            j++;
        }
        else j=fail[j];
    }
    return j;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",s1,s2);
        int l1=kmp(s1,s2);
        int l2=kmp(s2,s1);
        printf("%d\n",strlen(s1)+strlen(s2)-max(l1,l2));
    }
    return 0;
}
