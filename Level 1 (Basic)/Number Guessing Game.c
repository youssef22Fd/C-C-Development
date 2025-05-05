#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = rand() % 50 + 1; 
    int user_number;

    while(1)
    {
        printf("Enter a number: ");
        scanf("%d",&user_number);
    
        if(user_number < a)
           printf("guessing number is too low\n");
        
        else if(user_number > a)
           printf("guessing number is too High\n");
           
        else
        {
           printf("Good guessing! You're correct");
           break;
        }
    }
      
}
