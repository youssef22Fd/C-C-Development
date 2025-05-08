#include <stdio.h>
#include <stdint.h>

int main(){
	
        int8_t code;
	double n1, n2;
	
	printf("Enter the code: ");
	scanf("%c", &code);
	
	printf("Enter the numbers: ");
        scanf("%lf %lf", &n1, &n2);
	switch (code){
		
	    /* Addition */
	    case '+':
	        	printf("the add of %lf and %lf is %.2lf ",n1, n2, n1 + n2);
		        break;

	    /* subtraction */
	    case '-':
	        	printf("the sub of %lf and %lf is %.2lf ",n1, n2, n1 - n2);
		        break;

           /* multiplication */
	   case '*':
	        	printf("the mult of %lf by %lf is %.2lf ",n1, n2, n1 * n2);
		        break;

           /* division */
	   case '/':
	   
	        	if(n2 == 0)
	                 printf("the division by zero is undefined\n");
	        	printf("the div of %lf by %lf is %.2lf ",n1, n2, n1 / n2);
		        break;

	   default:
		        printf("invalid operation\n");
	}
}
