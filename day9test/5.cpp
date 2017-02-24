#include"iostream"
#include"cmath"
#include"queue"
#include"vector"
using namespace std;
int d[70000],s[70000];
queue<int> q;
using namespace std;
int main()
{
    int n;
    int sum=0;
    while(!q.empty()) q.pop();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d[i]>>s[i];
        if(d[i]==1) q.push(i);
        sum+=d[i];
    }
    cout<<sum/2<<endl;
    while(!q.empty())
    {
        int w=q.front();
        q.pop();
        if(d[w]<1) continue;
        cout<<w<<' '<<s[w]<<endl;
        s[s[w]]^=w;
        d[s[w]]--;
        if(d[s[w]]==1) q.push(s[w]);
    }
    /*int a=1;
    int b=2;

    a=a^b^4^5^6;
    cout<<a<<endl;*/
    return 0;
}
