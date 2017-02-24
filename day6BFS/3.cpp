#include"iostream"
#include"queue"
#include"cmath"
using namespace std;
queue<int>q;

int st,ed;

int v[10000];

int prime(int x)
{
    if(x==2||x==3) return 1;
    if(x<=1||x%2==0) return 0;
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return 0;
    return 1;
}
void BFS(int st,int y)
{


    while(!q.empty()) q.pop();
    q.push(st);
    while(!q.empty())
    {

        int x=q.front();
        //cout<<w<<endl;
        //cout<<endl;
        if(x==y) {cout<<v[x]<<endl; return;}
        int w;
        q.pop();
        //int k=x/10;
        for(int i=1;i<10;i+=2)
        {
            w=x/10*10+i;

            if(w!=x&&prime(w)&&v[w]==-1)
            {

                v[w]=v[x]+1;
                q.push(w);

            }
        }


        // k=x/100; int m=x%10;
        for(int i=0;i<10;i++)
        {
            w=x/100*100+i*10+x%10;

            if(w!=x&&prime(w)&&v[w]==-1)
            {
                v[w]=v[x]+1;
                q.push(w);

            }
        }

          //k=x/1000;  m=x%100;
        for(int i=0;i<10;i++)
        {
            w=x/1000*1000+i*100+x%100;

            if(w!=x&&prime(w)&&v[w]==-1)
            {

                v[w]=v[x]+1;
                q.push(w);

            }
        }
         //m=x%1000;
        for(int i=1;i<10;i++)
        {
            w=i*1000+x%1000;

            if(w!=x&&prime(w)&&v[w]==-1)
            {
                v[w]=v[x]+1;
                q.push(w);

            }
        }





    }
    cout<<"Impossible"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>st>>ed;
        for(int i=0;i<10000;i++) v[i]=-1;
        v[st]=0;
        BFS(st,ed);

    }
    return 0;
}
