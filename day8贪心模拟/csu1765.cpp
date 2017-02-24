#include"iostream"
#include"stdio.h"
#include"string"
#include"vector"
#include"string.h"
#include"memory.h"
using namespace std;
vector<int > g[100005];
int l[100005];
char s[10];
char loc[2000000];
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        strcpy(loc,"/1");
        int ll=2;
        int cur=1;
        memset(l,-1,sizeof(l));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) g[i].clear();
        n--;
        while(n--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            l[b]=a;
        }


        while(scanf("%s",s))
        {
            if(s[0]=='e') break;
            if(s[0]=='p')
            {
                for(int i=0;i<ll;i++) printf("%c",loc[i]); printf("\n");
            }
            else if(s[0]=='l')
            {
                if(!g[cur].empty())
                {
                  for(int i=0;i<g[cur].size()-1;i++)
                       printf("%d ",g[cur][i]);
                  printf("%d\n",g[cur][g[cur].size()-1]);

                }
            }
            else if(s[0]=='c')
            {
                scanf("%s",s);
                if(s[0]=='.') { cur=l[cur]; while(loc[ll-1]!='/') ll--; ll--;}
                else
                {
                    cur=0;
                    strcat(loc,"/"); ll++;
                    for(int i=0;i<strlen(s);i++)
                    {
                        cur=cur*10+(int)s[i]-48;

                        loc[ll++]=s[i];
                    }


                }
            }
        }


    }
    return 0;
}
