#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int stack_capacity;
    int size;
} Stack;


Stack *create_stack(int stack_capacity);
bool pop(Stack *stack, int *top);
bool push(Stack *stack, int top);
void display_stack(Stack *stack);



int main()
{
   
}


Stack *create_stack(int stack_capacity)
{
    if(stack_capacity <= 0)
       return NULL;
      
    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL)
      return NULL;
    
    stack->data = malloc(sizeof(int)*stack_capacity);
    if(stack->data == NULL)
    {
       free(stack);
       return NULL;
    }
    
    stack->stack_capacity = stack_capacity;
    stack->size = 0;
    
    return stack;
}





bool push(Stack *stack, int top)
{
    if(stack->size == stack->stack_capacity)
       return false;

    stack->data[stack->size] = top;
    stack->size++;
    
    return true;
}




void display_stack(Stack *stack)
{
    printf("Stack elements: \n");
    for (int i = stack->size-1; i >= 0; i--)
    {
        printf("%d\n", stack->data[i]);
    }
}



bool pop(Stack *stack, int *top)
{
    if(stack->size == 0)
    {
        printf("stack is empty\n");
        return false;
    }

    stack->size--;
    *top = stack->data[stack->size];
    return true;
}





