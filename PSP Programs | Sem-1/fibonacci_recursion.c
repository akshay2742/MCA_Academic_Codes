#include<stdio.h>

int fibonacci(int n)
{
	if(n<=1)
	{
		return n;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}
int main(){

	int i,n;
	
	printf("Enter the number: ");
	scanf("%d",&n);
	i=0;
	printf("Fibonacci series till %dth term is:\n",n);
	while(i<=n)
	{
		printf("%d ",fibonacci(i));
		i++;
	}
	printf("\n");

}
