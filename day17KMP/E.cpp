#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;

char str[1000000+5];
int fail[1000000+5];

void make_next()
{
    int i = 0,j = -1;
    memset(fail,0,sizeof(fail));
    fail[0] = -1;
    while (str[i])
    {
        if(j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            fail[i] = j;
        }
        else
        j = fail[j];
    }
}

void kmp()
{
    int i,len;
    for(i = 2;str[i-1];i++)
    {
        len= i-fail[i];
        if(i%len == 0 && i/len>1)
        printf("%d %d\n",i,i/len);
    }
}

int main()
{
    int n,cnt = 1;

    while(scanf("%d",&n)!=EOF && n)
    {
        scanf("%s",str);
        printf("Test case #%d\n",cnt++);
        make_next();
        kmp();
        cout<<endl;
    }

    return 0;
}


