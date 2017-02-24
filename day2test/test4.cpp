#include"iostream"
#include"string"
#include"stdlib.h"
using namespace std;
int main()
{
    int n,a,b,c,k;

    int l,flag;
    cin>>n;
    while(n--)
    {
        string s,s1,s2,s3,s4;
        cin>>s;
        l=s.length();
        k=0;

        while(s[k]>57&&k<l) s1+=s[k++];
        while(s[k]<=57&&k<l) s2+=s[k++];
        if(k==l) flag=1;
        else
        {
            flag=0;
            k++;
            while(s[k]<=57&&k<l) s3+=s[k++];
            a=atoi(s3.c_str());
        }

       if(flag==1)
       {
           cout<<"R"<<s2<<"C";
           l=s1.length();
           b=0;c=0;
           while(b<l)
           {
               c*=26;
               c+=int(s[b])-64;
               b++;
           }
           cout<<c<<endl;

       }
       else
       {
           b=a;
           char c;
           while(b/26!=0)
           {
               c=b%26+64;
               if(c==64) {c+=26; b-=26;}
               s4+=c;
               //cout<<char(b/27+64);
               b/=26;

           }

           if(b!=0)
           {
            c=b%26+64;
            if(c==64) c+=26;
            s4+=c;
           }
           for(int i=s4.length()-1;i>=0;i--) cout<<s4[i];
           cout<<s2<<endl;
       }



    }
    return 0;
}
