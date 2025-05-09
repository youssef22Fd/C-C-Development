/*
 * Sorting and Searching Algorithms Menu Program
 *
 * This program allows the user to interactively perform sorting and searching
 * operations on a dynamic array of integers through a text-based menu system.
 * Features:
 * - Sort array using Bubble Sort
 * - Sort array using Quick Sort
 * - Search for an element using Linear Search
 * - Search for an element using Binary Search (auto-sorts using Quick Sort)
 * - Display time taken for each operation
 * - Display time complexity of each algorithm on exit
 * Functions:
 * - display_menu(): Displays the available operations
 * - read_menu(): Reads and returns the user’s menu selection
 * - menu_bar(): Handles the logic for selected operations
 * - printArray(): Prints the current array
 * - Bubble_sort(): Implements Bubble Sort algorithm
 * - quickSort(): Implements Quick Sort using recursion
 * - partition(): Helper for Quick Sort (Lomuto partition scheme)
 * - linear_search(): Searches for a value using Linear Search
 * - binary_search(): Searches for a value using Binary Search (on a sorted array)
 * - compareTimeComplexity(): Displays Big-O time complexities of algorithms
 *
 * Note that the Binary Search requires the array to be sorted and is automatically preceded by Quick Sort 
 * and Execution time is measured using <time.h>
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void display_menu();
int read_menu();
void menu_bar(int arr[], int length, int menu_code);
void printArray(int arr[], int n);
void Bubble_sort(int arr[], int length);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void binary_search(int arr[], int search_value, int length); 
void linear_search(int arr[], int search_value, int length);
void compareTimeComplexity();


int main()
{
    int menu_code;
    int length;
    int continue_appl = 0;


    printf("Enter number of elements: ");
    scanf("%d", &length);

    int *arr = (int *)malloc(length * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < length; i++)
        scanf("%d", &arr[i]);
    
    while (!continue_appl)
    {
        display_menu();
        menu_code = read_menu();

        if (menu_code != 5)
            menu_bar(arr, length, menu_code);
        else
        {
            continue_appl = 1;
            printf("Exiting application...\n");
        }
    }

    compareTimeComplexity();
    free(arr);
    return 0;
}



void display_menu()
{  
    printf("**************************************************\n");
    printf("  Sorting using Bubble sort click on     :     1\n");
    printf("  Sorting using Quick sort click on      :     2\n");
    printf("  Searching using Linear search click on :     3\n");
    printf("  Searching using Binary search click on :     4\n");
    printf("  Exit the application click on          :     5\n");
    printf("**************************************************\n");
    printf("Enter your application here: ");
}

int read_menu()
{
    int code;
    scanf("%d", &code);
    return code;
}

void menu_bar(int arr[], int length, int menu_code)
{
    clock_t start, end;
    int search_value;

    switch (menu_code) 
    {
        case 1:
            printf("\nSorted array using Bubble Sort:\n");
            start = clock();
            Bubble_sort(arr, length);
            end = clock();
            printArray(arr, length);
            break;

        case 2:
            printf("\nSorted array using Quick Sort:\n");
            start = clock();
            quickSort(arr, 0, length - 1);
            end = clock();
            printArray(arr, length);
            break;

        case 3:
            printf("\nEnter the element to search: ");
            scanf("%d", &search_value);
            start = clock();
            linear_search(arr, search_value, length);
            end = clock();
            break;

        case 4:
            printf("\nEnter the element to search: ");
            scanf("%d", &search_value);
            start = clock();
            quickSort(arr, 0, length - 1);
            binary_search(arr, search_value, length);
            end = clock();
            break;

        default:
            printf("Invalid choice!\n");
            return;
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n\n", time_taken);
}

void printArray(int arr[], int length) {
    for (int i = 0; i<length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void Bubble_sort(int arr[], int length)
{
    for(int i=0; i<length  ; i++)
    {
        for(int j=0; j<length-1; j++)
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



void binary_search(int arr[], int search_value, int length) 
{
    int first = 0;
    int last = length - 1;
    int middle;

    while (first <= last) {
        middle = (first + last) / 2;

        if (arr[middle] < search_value) {
            first = middle + 1;
        } else if (arr[middle] == search_value) {
            printf("The value %d found at the position %d\n", search_value, middle + 1);
            return;
        } 
        else 
            last = middle - 1;
    }

    printf("The value %d is not in this array\n", search_value);
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
        printf("there is no such value in this array!\n");
}


void compareTimeComplexity()
{
    printf("Time Complexity:\n");
    printf("Bubble Sort complexity is   : O(n^2)\n");
    printf("Quick Sort complexity is    : O(nlog(n))\n");
    printf("Linear Search complexity is : O(n)\n");
    printf("Binary Search complexity is : O(log(n))\n");
}
