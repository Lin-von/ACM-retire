#include"iostream"
#include"algorithm"
using namespace std;
int v[100],s[100];
int w;

int n,sum,k;
int cmp(int a,int b)
{
    return a>b;
}
/*int dfs(int left,int x,int sum)
{
    if(left==0)
    {
        sum-=k;
        if(sum==0) return 1;
        x=0;
        while(v[x]) x++;
       //cout<<k<<endl; cin>>w;
        v[x]=1;
        if(dfs(x+1,k-s[x],sum))return 1;
        v[x]=0;
        sum+=k;
    }
    else
    {
        for(int i=x;i<n;i++)
        {
            if(i>0&&(s[i]==s[i-1])&&!v[i-1]) continue;
            if(!v[i]&&(s[i]<=left))
            {
                v[i]=1;
                //cout<<i<<endl; cin>>w;
                left-=s[i];
                //cout<<left<<endl;
                if(dfs(left,i,sum)) return 1;
                left+=s[i];
                v[i]=0;
                if(s[i]==left) break;

            }
        }
    }
    return 0;
}*/

int dfs(int les,int x,int sl)
{
    if(les==0)
    {
        sl-=k;
        if(sl==0) return 1;
        int i=0;
        while(v[i]) i++;
        v[i]=1;
        if(dfs(k-s[i],i+1,sl)) return 1;
        v[i]=0;
        sl+=k;


    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(i>0&&(s[i]==s[i-1]&&!v[i-1])) continue;
            if(!v[i]&&s[i]<=les)
            {
                les-=s[i];
                v[i]=1;
                if(dfs(les,i,sl)) return 1;
                v[i]=0;
                les+=s[i];

                if(s[i]==les||les==k) break;
            }
        }
    }
    return 0;
}
int main()
{
    while(1)
    {
        cin>>n;
        if(n==0) break;
        sum=0;

        for(int i=0;i<n;i++) { cin>>s[i]; sum+=s[i]; v[i]=0;}
        sort(s,s+n,cmp);
        // for(int i=0;i<n;i++) cout<<s[i];
       // k=s[0];

       /* while(sum%k!=0) k++;
        //cout<<k<<endl;
        while(dfs(k,0,sum)==0)
        {
            k++;
            while(sum%k==0) k++;
        }*/
        int flag=0;
        for(k=s[0];k<=sum/2;k++)
        {
            if(sum%k==0)
            {
                if(dfs(k,0,sum))
                {
                    flag=1;
                    cout<<k<<endl;
                    break;
                }
            }
        }
        if(flag==0)
            cout<<sum<<endl;
        //cout<<k<<endl;
    }
}
