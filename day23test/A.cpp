#include"iostream"
#include"string.h"
using namespace std;
int fa[100000+5];
int v[100000+5];
int flag;
int Find(int x) {
    return fa[x] == x ? x : fa[x] = Find(fa[x]) ;
}
void Merge(int u ,int v) {
    int fu = Find(u) , fv = Find(v) ;
    if(fu != fv) fa[fv] = fu ;
    else flag=0;

}


int main()
{
    int x,y;
    int cas=1;
    while(cin>>x>>y)
    {

        if(x==-1&&y==-1) break;
        if(x==0&&y==0) {cout<<"Case "<<cas++<<' '<<"is a tree."<<endl; continue;}
        for(int i=1;i<100000+5;i++)
        {
            v[i]=0;
            fa[i]=i;
        }
        flag=1;
        v[x]=1;
        v[y]=1;
        Merge(x,y);
        while(cin>>x>>y)
        {
            if(x==0&&y==0) break;
            v[x]=1;
            v[y]=1;
            Merge(x,y);
           // if(flag==0) break;

        }

        if(flag==0) {cout<<"Case "<<cas++<<' '<<"is not a tree."<<endl; continue;}
        int cnt=0;
        for(int i=1;i<100000+5;i++)
        {
            if(v[i]&&fa[i]==i) cnt++;
            if(cnt>1) {flag=0; break;}
        }
        if(flag==1) cout<<"Case "<<cas++<<' '<<"is a tree."<<endl;
        else cout<<"Case "<<cas++<<' '<<"is not a tree."<<endl;

    }
    return 0;
}
