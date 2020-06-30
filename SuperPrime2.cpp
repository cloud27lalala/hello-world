#include<stdio.h>
#include<math.h>

int isprime(int x)
{
	for (int i=2;i<=sqrt(x);i++)
	{
		if (x%i==0)
		  return 0;
	}
	return 1;
}
void splitnum(int x,int a[])
{
	int n=1,m=10;
	int y;
	y=x;
	while(y%10>0)
	{
		n++;
		y=y/10;
	}
	a[0]=n;
	for (int i=1;i<=n;i++)
	{
		a[n-i+1]=x%m;
		m*=10;
	}
}

int main()
{
	float sum=0,n=0;
	int arg;
	for (int i=100;i<=10000;i++)
	{
		if (isprime(i)==1)
		{
			int a[6]={0};//a[0]ÎªÎ»Êý 
			int sum1=0,sum2=0;
			splitnum(i,a);
			for (int j=1;j<=a[0];j++)
			{
				sum1+=a[j];
				sum2+=a[j]*a[j];
			}
			if ( isprime(sum1) && isprime(sum2) )
			{
				printf("%d\n",i);
				sum+=i;
				n++;
			}
		}
	}
	printf("%.2f\n",sum/n);
	return 0;
}
