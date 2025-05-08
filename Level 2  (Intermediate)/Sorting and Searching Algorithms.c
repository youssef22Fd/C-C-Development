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
    int n = sizeof(arr)/sizeof(int);
    int i = low;
    for(int j=low+1; j<high; j++)
    {
        if(arr[j] <= arr[high])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    
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




