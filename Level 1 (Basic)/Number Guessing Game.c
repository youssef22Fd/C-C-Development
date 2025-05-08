/*
 * Number Guessing Game
 *
 * This program generates a random number between 1 and 50 using the rand() function
 * and asks the user to guess it. After each guess, it gives feedback:
 *  - If the guess is lower than the target number, it informs the user it's too low.
 *  - If the guess is higher than the target number, it informs the user it's too high.
 *  - If the guess matches the target, it congratulates the user and exits.
 *
 * The random number generator is seeded with the current time using time(0)
 * to ensure different outcomes on each execution.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
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
