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
    a=s[0];
    d=s.substr(2,s.find('e')-2);
    c=s.substr(s.find('e')+1,s.length()-s.find('e'));
    b=atoi(c.c_str())+1;
    /*cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<endl;*/

    a+=d;
    while(a.length()<b) a+='0';
    //cout<<a<<endl;
    a=a.substr(0,b)+'.'+a.substr(b,a.length()-b);
    //cout<<a<<endl;
    int l=0;
    while(a[0]=='0') { a=a.substr(1,a.length()-1); l++;}
   // cout<<a<<endl;
    l=a.length()-1;
    while(a[a.length()-1]=='0') { a=a.substr(0,a.length()-1); l--;}
   // cout<<a<<endl;
    if(a[0]=='.') a='0'+a;
    if(a[a.length()-1]=='.') a=a.substr(0,a.length()-1);
    cout<<a<<endl;
    return 0;
}
