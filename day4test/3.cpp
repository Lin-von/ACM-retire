#include"iostream"
using namespace std;
long long x;
int p[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
int n;
long long y=1e18;
void dfs(long long x,int cur,int loc)
{
    if(cur>n) return;
    if(cur==n&&y>x) { y=x;  return;}
    for(int i=1;i<64;i++)
    {
        x*=p[loc];
        if(x<y) dfs(x,cur*(i+1),loc+1);
        else break;
    }

}
int main()
{
    cin>>n;
    dfs(1,1,0);
    cout<<y<<endl;
    return 0;
}
