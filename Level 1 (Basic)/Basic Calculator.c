#include <stdio.h>
#include <stdint.h>

int main(){
	
        int8_t code;
	int32_t n1, n2;
	
	printf("Enter the numbers: ");
        scanf("%d %d", &n1, &n2);

	printf("Enter the code: ");
	scanf("%c", &code);
	switch (code){
		
	    /* Addition */
	    case '+':
                printf("the add is %d ", n1 + n2);
		break;

	    /* subtraction */
	    case '-':
                printf("the sub is %d ", n1 - n2);
		break;

           /* multiplication */
	   case '*':
                printf("the mult is %d ", n1 * n2);
		break;

           /* division */
	   case '/':
		if(n2==0)
		{
	       printf("the division by zero is undefined\n");
		   break;
		}
		printf("the div is %d ", n1 / n2);
		break;

	   default:
		printf("invalid operation\n");
	}

}
