#include"iostream"
#include"string.h"
#include"stdio.h"
using namespace std;

char s[12][62];
char temp[62];
int n,maxx,lent,fail[62];

void getfail()
{
    int i=0,j=-1;
    fail[0]=-1;
    while(i<lent)
    {
        if(j==-1||temp[i]==temp[j])
        {
            i++;  j++;
            fail[i]=j;

        }
        else j=fail[j];
    }

}

void kmp()
{

    int k,m,i,j;
    getfail();
    maxx=100;
    for(k=1;k<n;k++)
    {
        i=0;j=0;m=0;
        while(i<60&&j<lent)
        {
            if(j==-1||s[k][i]==temp[j])
            {
                i++; j++;
            }
            else j=fail[j];
            if(j>m) m=j;
        }
        if(m<maxx) maxx=m;
    }
}

int main()
{
   // freopen("F:\\in.txt", "r", stdin);
   // freopen("F:\\out.txt", "w", stdout);
    int t,i;
    char sub[62];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>s[i];
        int ans=0;
       // for(int i=0;i<n;i++)
         //   cout<<s[i]<<endl;
        for(int i=0;i<=57;i++)
        {
            strcpy(temp,s[0]+i);
            lent=60-i;
            kmp();
            if(ans<maxx)
            {
                ans=maxx;
                strncpy(sub,s[0]+i,ans);
                sub[ans]='\0';

            }
            else if(ans==maxx)
            {
                char tem[62];
                strncpy(tem,s[0]+i,ans);
                tem[ans]='\0';
                if(strcmp(tem,sub)<0)
                    strcpy(sub,tem);
            }
        }

        if(ans>=3)
            cout<<sub<<endl;
        else cout<<"no significant commonalities"<<endl;
    }

    return 0;
}
