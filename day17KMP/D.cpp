#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;
char a[1000+5],b[1000+5];
int fail[1000+5];
void make_next(char *b)
{
    int l=strlen(b);
    int i=0,j=-1;
    fail[0]=-1;
    while(i<l)
    {
        if(j==-1||b[i]==b[j])
            {
                i++;
                j++;
                fail[i]=j;
            }
        else
            j=fail[j];
    }
}
int main()
{
    while(scanf("%s",a))
    {
        if(a[0]=='#'&&a[1]=='\0')
            break;
        scanf("%s",b);
        make_next(b);
        int sum=0;

        int l1=strlen(a);
        int l2=strlen(b);

        if(l2>l1)
            printf("0\n");
        else
        {
            int i=0,j=0;
            while(i<l1)
            {
                if(j==-1||a[i]==b[j])
                    i++,j++;
                else
                    j=fail[j];
                if(j==l2)
                {
                    j=0;
                    sum++;
                }
            }
            printf("%d\n",sum);
        }

    }
    return 0;
}
