#include"iostream"
#include"cmath"
#include"iomanip"
#include"stdio.h"
#include"string"
#include"queue"
#include"vector"
using namespace std;
priority_queue<int ,vector<int >,greater<int> > q;
int v[1000005];
char c[1000005];
int n,m;
char  s[10];
int x;
int main()
{
    int sum=0;
    while(!q.empty()) q.pop();
    cin>>n;
    while(n--)
    {
        //cout<<1<<endl;
        scanf("%s",s);  //cout<<s<<endl;
        if(s[0]=='i')
        {
            scanf("%d",&x);   //cout<<x<<endl;
            q.push(x);
            c[sum]='i';
            v[sum++]=x;
        }
        else if(s[0]=='r')
        {
            if(q.empty())
            {
                c[sum]='i';
                v[sum++]=0;
                c[sum++]='r';

            }
            else
            {
                q.pop();
                c[sum++]='r';
            }

        }
        else if(s[0]=='g')
        {

            scanf("%d",&x); //cout<<x<<endl;
            if(q.empty())
            {
                c[sum]='i';
                v[sum++]=x;
                q.push(x);
                c[sum]='g';
                v[sum++]=x;
            }
            else
            {
                //int w=q.top();
                while(!q.empty()&&q.top()<x)
                {
                    c[sum++]='r';
                    q.pop();
                    //if(!q.empty()) w=q.top();
                } //cout <<1<<endl;
                if(!q.empty()&&q.top()==x)
                {
                    c[sum]='g';
                    v[sum++]=x;

                }
                else
                {
                    c[sum]='i';
                    v[sum++]=x;
                    q.push(x);
                    c[sum]='g';
                    v[sum++]=x;
                }
            }

        }
    }


    cout<<sum<<endl;
    for(int i=0;i<sum;i++)
        if(c[i]=='i')  printf("insert %d\n", v[i]);
        else if(c[i]=='r') printf("removeMin\n");
        else if(c[i]=='g') printf("getMin %d\n",v[i]);
     return 0;
}
