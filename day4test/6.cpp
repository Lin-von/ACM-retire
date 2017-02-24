#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;
int main()
{
    char s1[1000010],s2[1000010];
    scanf("%s",s1);
    scanf("%s",s2);
    int p=0,q=0;
    while(s1[p]=='0') p++;
    while(s2[q]=='0') q++;
    //cout<<strlen(s1)-p<<strlen(s2)-q<<endl;
    if(strlen(s1)-p>strlen(s2)-q) cout<<'>'<<endl;
    else if(strlen(s1)-p<strlen(s2)-q) cout<<'<'<<endl;
    else
    {
    while(s1[p]==s2[q]&&p<strlen(s1)&&q<strlen(s2)) {p++;q++;}
    //cout<<p<<q<<endl;
    if(p==strlen(s1)&&q==strlen(s2)) cout<<'='<<endl;
    else if(s1[p]>s2[q]) cout<<'>'<<endl;
    else if(s1[p]<s2[q]) cout<<'<'<<endl;
    }


    return 0;
}
