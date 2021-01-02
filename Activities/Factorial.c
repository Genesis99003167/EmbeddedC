#include<stdio.h>
int factorial(int);
int main()
{
int num, fact;
printf("Enter any integer number: ");
scanf("%d",&num);

fact=factorial(num);

printf("FActorial of %d is: %d", num, fact);

return 0;

}

int factorial(int i)
{
	if(i==0)
		return(1);
	
	return(i*factorial(i-1));	
}
