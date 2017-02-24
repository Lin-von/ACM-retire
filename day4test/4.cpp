#include"iostream"
#include"string.h"
#include"cmath"
using namespace std;
char d[10001][16];
char w[16];

int ld=0,lw=0;
int dlen[10001];
char ed[5]="#";
void work(char* str,int l,int k)
{
    //cout<<l<<' '<<dlen[k]<<endl;
    if(l==dlen[k])
    {
            int cnt=0;
            for(int i=0;i<l;i++) if(str[i]==d[k][i]) cnt++;
            if(cnt==l-1) cout<<" "<<d[k];

    }
    else if(l==dlen[k]-1)
    {
        for(int i=0;i<dlen[k];i++)
        {
           char temp[16]="";
           char temp1[16]="";
           strncpy(temp,d[k],i);
           strncpy(temp1,d[k]+i+1,dlen[k]-i-1);
           strcat(temp,temp1);
           //cout<<temp<<endl;
           //cout<<str<<endl;
           if(strcmp(str,temp)==0) { cout<<" "<<d[k]; break;}

        }
    }
    else if(l==dlen[k]+1)
    {
        for(int i=0;i<l;i++)
        {
           char temp[16]="";
           char temp1[16]="";
           strncpy(temp,str,i);
           strncpy(temp1,str+i+1,l-i-1);
           strcat(temp,temp1);
           //cout<<temp<<endl;
          // cout<<d[k]<<endl;
           if(strcmp(d[k],temp)==0) { cout<<" "<<d[k]; break;}
        }
    }
}


int main()
{
    while(cin>>d[ld])
    {
        if(strcmp(d[ld],ed)==0) break;
        ld++;
    }
    for(int i=0;i<ld;i++) dlen[i]=strlen(d[i]);

    while(cin>>w)
    {
        int flag=0;
        if(strcmp(w,ed)==0) break;
        lw=strlen(w);
        //cout<<w;
        for(int i=0;i<ld;i++)
        {

            if(strcmp(w,d[i])==0) { cout<<w<<" is correct"<<endl; flag=1; break;}

        }
        if(flag==0)
        {
            cout<<w<<":";
        for(int i=0;i<ld;i++)
        {
            if(abs(lw-dlen[i])<=1)
            work(w,lw,i);
        }
        cout<<endl;
        }

    }





}
