#include"iostream"
#include"string"
#include"string.h"
using namespace std;
int k[26+5][26+5];
string s1,s2;
int main()
{
    int n;
    while(cin>>n)
    {
        memset(k,0,sizeof(k));
        cin>>s1;
        cin>>s2;
        int sum=0;
        int flag=1;
        for(int i=0;i<n;i++)
            if(s1[i]!=s2[i])
        {
            k[s1[i]-'a'][s2[i]-'a']=i+1;
            sum++;
        }

        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
            if(k[i][j]&&k[j][i]&&flag)
            {
                cout<<sum-2<<endl;
                cout<<k[i][j]<<' '<<k[j][i]<<endl;
                flag=0;
                break;
            }

       if(flag)
       for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                for(int z=0;z<26;z++)
            if(k[i][j]&&k[j][z]&&flag)
            {
                cout<<sum-1<<endl;
                cout<<k[i][j]<<' '<<k[j][z]<<endl;
                flag=0;
                break;
            }
        if(flag)
        {
            cout<<sum<<endl;
            cout<<-1<<' '<<-1<<endl;
        }


    }

    return 0;
}
