#include <stdio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}


int partition(int arr[], int left, int right)
{
    int pivot = arr[right]; 
    int pIndex = left;     

    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivot)                
            swap(&arr[i], &arr[pIndex++]); 
    }
    swap(&arr[pIndex], &arr[right]); 

    return pIndex;
}

void quickSort(int arr[], int left, int right)
{
    if (left >= right) 
        return;

    int pIndex = partition(arr, left, right); 
    quickSort(arr, left, pIndex - 1);         
    quickSort(arr, pIndex + 1, right);       
}

int main()
{
    int arr[100], size;
    printf("\nEnter size ");
    scanf("%d", &size);
    printf("\nEnter array ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}


