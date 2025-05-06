#include <stdio.h>
#include <stdint.h>
int main(){
	
        int8_t code;
	int32_t n1, n2;
	printf("Enter the code: ");
	fflush(stdout);
	scanf("%c", &code);

	switch (code){

	/* Addition */
	case 'a':
	        printf("Enter the numbers: ");
        	scanf("%d %d", &n1, &n2);
                printf("the add is %d ", n1 + n2);
		break;

	/* subtraction */
	case 's':
	        printf("Enter the numbers: ");
        	scanf("%d %d", &n1, &n2);
                printf("the sub is %d ", n1 - n2);
		break;

        /* multiplication */
	case 'm':
	        printf("Enter the numbers: ");
        	scanf("%d %d", &n1, &n2);
                printf("the mult is %d ", n1 * n2);
		break;

        /* division */
	case 'd':
	       printf("Enter the numbers: ");
               scanf("%d %d", &n1, &n2);
		if(n2==0)
	             printf("the division by zero is undefined\n");
                printf("the div is %d ", n1 / n2);
		break;

	default:
		printf("invalid operation\n");
	}

}
