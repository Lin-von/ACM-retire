#include"iostream"
#include"string.h"
#include"string"
#include"stdio.h"
using namespace std;
char s[100000+10];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]=='[')
            {
                int j=i+1;

                while(s[j]!='['&&s[j]!=']'&&j<=len-1)
                {
                    printf("%c",s[j]);
                    j++;
                }
            }


        }
        int j=0;
        while(s[j]!='['&&s[j]!=']'&&j<=len-1)
            {
                printf("%c",s[j]);
                j++;
            }
        for(int i=0;i<len;i++)
        {
            if(s[i]==']')
            {
                int j=i+1;
                while(s[j]!='['&&s[j]!=']'&&j<=len-1)
                {
                    printf("%c",s[j]);
                    j++;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
