#include"iostream"
#include"stdlib.h"
#include <math.h>
using namespace std;


int a[100];
int c[11];
int n,sum=0;


int test(int row, int col)
{
	int i;
	for (i=1; i<row;++i)
			{
		if (a[i]==col||abs(i-row)==abs(a[i]-col))
			return 0;
	}
	return 1;
}




void Trial(int i,int n) {

      if  (i>n)  sum++;
      else
          for(int j=1; j<=n; j++) {
              a[i]=j;
              if (test(i,j))    Trial(i+1,n);

              a[i]=-100;

          }
}

int main(void)
{


	c[1]=1;
	for(int k=2;k<=10;k++)
      {
          for(int i=1;i<=k;i++) a[i]=-100;
          sum=0;
          for(int i=1;i<=k;i++)
          {
           a[1]=i;
           Trial(2,k);
          }
          c[k]=sum;
      }

    cin>>n;
    while(n!=0)
    {
        cout<<c[n]<<endl;
        cin>>n;
    }








	return 0;
}
