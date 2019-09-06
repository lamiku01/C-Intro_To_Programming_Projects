//this program acts as a calculator 

//Lauren Mikula
//Lab #3
//Section 2
//1/24/19
#include<stdio.h>
#include<stdbool.h>

int main()//main function
{ 
	float FirstNumber, SecondNumber, answer;
	int dividend, divisor, remainder, choice, y;
	int x = 0;
	int div = 2;
	do {
	printf("\n\nCalculator menu: \n1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Modulus (integers only) \n6. Test if prime (integers only) \n7. Exit");
	printf("\n\n Please choose an opperation: ");
	scanf("%d",&choice);
	if (choice ==1)	//addition
	{
		printf("\nEnter the first number: ");
		scanf("%f",&FirstNumber);
		printf("Enter the second number: ");
		scanf("%f",&SecondNumber);
		answer = FirstNumber + SecondNumber;
		printf("%f + %f = %f", FirstNumber, SecondNumber, answer);
		
	}
	if (choice ==2) //subtraction
	{	
		printf("\nEnter the first number: ");
		scanf("%f",&FirstNumber);
		printf("Enter the second number: ");
		scanf("%f",&SecondNumber);
		answer = FirstNumber - SecondNumber;
		printf("%f - %f = %f", FirstNumber, SecondNumber, answer);
	}
	if (choice ==3) //multiplication
	{
		printf("\nEnter the first number: ");
		scanf("%f",&FirstNumber);
		printf("Enter the second number: ");
		scanf("%f",&SecondNumber);
		answer = FirstNumber * SecondNumber;
		printf("%f * %f = %f", FirstNumber, SecondNumber, answer);
	}
	if (choice ==4) //division
	{
		printf("\nEnter the first number: ");
		scanf("%f",&FirstNumber);
		printf("Enter the second number: ");
		scanf("%f",&SecondNumber);
		answer = FirstNumber / SecondNumber;
		printf("%f / %f = %f", FirstNumber, SecondNumber, answer);
	}
	
	if (choice ==5) //modulus
	{
	
		printf("\nEnter the dividend: ");
		scanf("%d",&dividend);
		printf("Enter the divisor: ");
		scanf("%d",&divisor);
		remainder = dividend % divisor;
		printf("%d %% %d = %d", dividend, divisor, remainder);
	}
	if (choice ==6) //test if prime
	{
		printf("\nPlease enter a number to be tested: " );
		scanf("%d", &x);
	
		if(x==2)
			printf("%d is prime", x);
		else
			while (x % div != 0)
			{
				div++;
			}
			if(x % div == 0 && x != div && x > 0)
				{
					y = x / div;
					printf("\n%d is not prime",x);
					printf("\n%d * %d = %d", y, div, x );
				}
			else
				printf("\n%d is prime", x);
	}
	else if (choice ==7) //exit
	{
		printf("Goodbye");
	}
	}
	while(choice != 7);
	
}//end main
