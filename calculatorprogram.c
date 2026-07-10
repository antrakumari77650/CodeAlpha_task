#include<stdio.h>
int main()
{
	int n; 
	float a,b,c;
	printf("Enter two numbers ");
	scanf("%f %f",&a,&b);
	printf("1 for addition \n2 for substraction \n3 for multiplication \n4 for division\n");
	scanf("%d",&n);
	switch(n){
	
	   case 1: c=a+b;
	           printf("addition is %f",c);
	           break;
	   case 2: c=a-b;
	           printf("substraction is %f",c);
	           break;
	   case 3: c=a*b;
	           printf("multiplication is %f",c);
	           break;
	   case 4:c=a/b;
               printf("division is %f",c);
               break;
	   default:
	   	printf("Invalid input");
	}
	return 0;
}