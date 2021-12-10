#include<stdio.h>

int factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	return n*factorial(n-1);

}

int main(){

	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	printf("\nFactorial of %d is %d\n",n,factorial(n));
}
