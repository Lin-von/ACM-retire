#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

char s[100000+10];
int fail[100000+10];

void getNext(char *p)
{
    int j,k;
    j=0;  k=-1;
    int len=strlen(p);
    fail[0]=-1;
    while(j<len)
    {
        if(k==-1||p[j]==p[k])
        {
            j++;
            k++;
            fail[j]=k;
        }
        else k=fail[k];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        getNext(s);
        int len=strlen(s);
        if(fail[len]==0)
        {
            printf("%d\n",len);
            continue;
        }
        int t=len-fail[len];
        if(len%t==0)printf("0\n");
        else
        {
            printf("%d\n",t-len%t);
        }
    }
    return 0;
}
