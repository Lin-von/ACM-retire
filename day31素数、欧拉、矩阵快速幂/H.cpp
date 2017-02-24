#include"iostream"
#include"cmath"
#include"string.h"
using namespace std;
const int modd=9973;
long long  n,k;
struct Matrix{
    long long mat[10+2][10+2];

    Matrix operator*(const Matrix m) const{
        Matrix temp;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            temp.mat[i][j]=0;
            for(int k=0;k<n;k++)
            {
                temp.mat[i][j]+=mat[i][k]*m.mat[k][j]%modd;
                temp.mat[i][j]%=modd;
            }
        }
    return temp;
    }

};

long long pow(Matrix &m,int k)
{

    Matrix ans;
    memset(ans.mat,0,sizeof(ans.mat));
    for(int i=0;i<n;i++) ans.mat[i][i]=1;
    while(k)
    {
        if(k&1) ans=ans*m;
        k>>=1;
        m=m*m;
    }
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ans.mat[i][i]%modd;
        sum%=modd;
    }
    return sum;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        Matrix mm;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>mm.mat[i][j];
            cout<<pow(mm,k)<<endl;
    }
    return 0;
}
