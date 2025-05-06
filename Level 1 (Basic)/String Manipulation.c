#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* reverse(char myString[]);
int counting_vowels(char myString[]);
void string_palindrome(char myString[]);

char myReverseString[30];

int main() {
    char myString[30];
    printf("Enter your string: ");
    scanf("%s",myString);
    char* myReverseString = reverse(myString);
    printf("Reversed string is: %s\n", myReverseString);
    int count = counting_vowels(myString);
    printf("the number of vowels is: %d\n", count);
    string_palindrome(myString);
    return 0;
}


char* reverse (char myString[])
{   
    int n = strlen(myString);
    
    strcpy(myReverseString, myString);
    
    for(int i=0; i< n/2; i++)
    {  
        char temp = myReverseString[i];
        myReverseString[i] = myReverseString[n-1-i];
        myReverseString[n-1-i] = temp;
    }
   return myReverseString;
}

int counting_vowels(char myString[])
{    
    int count = 0;
    int n = strlen(myString);
    
    for(int i=0; i<n; i++)
    {
       myString[i] = tolower(myString[i]);
       if(myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' || myString[i] == 'o' || myString[i] == 'u')
          count += 1;
    }
    return count;
}

void string_palindrome(char myString[])
{
    char* myReverseString = reverse(myString);
    int n = strlen(myReverseString);
    
    for(int i=0; i<n; i++)
    {
        if(myReverseString[i] != myString[i]) 
        {
           printf("The String is not palindrome");
           break; 
        }
        printf("The String is palindrome");  
        break;
  
    }
    
} 




