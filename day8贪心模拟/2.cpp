#include"iostream"
#include"stdlib.h"
#include"string"
using namespace std;
string s;
string a,d,c;
int b;
int main()
{
    cin>>s;
    int k,l=-1,r=s.length()-1;
    k=s.find('.');
    if(k==-1) k=s.length();
    for(int i=0;i<s.length();i++)
    if(s[i]!='0'&&s[i]!='.') {l=i; break;}
    for(int i=s.length()-1;i>=0;i--)
    if(s[i]!='0'&&s[i]!='.') {r=i; break;}
    if(l==-1) cout<<0<<endl;
    else
    {

        if(k>l) k=k-l-1;
        else k=k-l;

        cout<<s[l];
        if(l!=r) cout<<'.';
        for(int i=l+1;i<=r;i++)
            if(s[i]!='.') cout<<s[i];
        if(k!=0) cout<<"E"<<k;
        cout<<endl;
    }


    /*if(s=="."||s=="") {cout<<0<<endl; return 0;}
    int k=s.find('.');



     cout<<a<<endl;



    if(a=="0"||a.length()==0)
    {
        int l=0;
        while(d[0]=='0') { d=d.substr(1,d.length()-1); l++; }
        d=d.substr(0,1)+'.'+d.substr(1,a.length()-1);
        if(d[d.length()-1]=='.') d=d.substr(0,d.length()-1);
        cout<<d<<"E"<<-(l+1);
    }
    else if(a.length()==1)
    {
        cout<<s<<endl;
    }
    else
    {
        int l=a.length()-1;
        a+=d;
        a=a.substr(0,1)+'.'+a.substr(1,a.length()-1);
        while(a[a.length()-1]=='0') { a=a.substr(0,a.length()-1); }
        if(a[a.length()-1]=='.') a=a.substr(0,a.length()-1);
        cout<<a<<"E"<<l<<endl;
    }*/



    return 0;
}
