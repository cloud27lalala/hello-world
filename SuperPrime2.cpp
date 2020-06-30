/*
//��ҵ��ɾ������ļ����࣬ʹ�ü̳з���ʵ����ͬ�Ĺ��ܡ� 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  //2��number-1������ 
  	  return false;
	}
  private:
  	const int number;
}; 
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  set = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //���ٶ��� 
		delete set[i]; 
	  delete[] set;
	}
 	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isPrime())
  	      count += 1;
	  return count; 
	}

	bool add(int n) {
	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  set[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!set[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **set;
	int size, index;
};
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0), pset(3) {  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):Prime(n), pset(3) {
	  // number split into N
	  int temp = n;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	pset.add(t);  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	  } 
	}
  	~SuperPrime() {
	}
  	bool isPrime() {   //��/����Ľӿڣ�������˵����� 
	  if (Prime::isPrime() && pset.isAllPrime())
	    return true; 
  	  return false;
	}
  private:
  	PrimeSet pset;
	int sum() {
	  return 0;
	}
	int multi() {
	  return 0;
	}
	int squareSum() {
	  return 0;
	}
};
int main() {
  SuperPrime sp(113);
  if (sp.isPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
*/
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
			int a[6]={0};//a[0]Ϊλ�� 
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
