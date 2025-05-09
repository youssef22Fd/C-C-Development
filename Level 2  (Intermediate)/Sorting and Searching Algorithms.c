#include <stdio.h>
#include <stdint.h>


void Bubble_sort(int arr[])
{
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n  ; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int partition(int arr[], int low, int high)
{   
    int pivot_value = arr[high];
    int i = low;
    for(int j=low; j<high; j++)
    {
        if(arr[j] <= pivot_value)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int tmp = arr[i];
    arr[i] = arr[high];
    arr[high] = tmp;
    return i;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pivot_index = partition(arr, low, high); 
        quickSort(arr, low, pivot_index - 1);       
        quickSort(arr, pivot_index + 1, high);      
    }
}



void linear_search(int arr[], int search_value, int length)
{
    int i = 0;
    for(i=0; i<length; i++)
    {
        if(arr[i] == search_value)
        {
            printf("the value %d found at position %d\n", search_value, i+1);
            break;
        }
    }
    if(i == length)
        printf("there is no such value in this array!");
}


void binary_search(int arr[], int search_value, int length)
{
    int first = 0;
    int last = length - 1;
    int middle;

    while (first <= last) {
        middle = (first + last) / 2;

        if (arr[middle] < search_value) {
            first = middle + 1;
        } else if (arr[middle] == search_value)
        {
            printf("The value %d found at the position %d\n", search_value, middle + 1);
            return;
        } 
        else 
            last = middle - 1;
    }
    printf("The value %d is not in this array\n", search_value);
}














