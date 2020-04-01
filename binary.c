#include <cs50.h>
#include <stdio.h>

void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}


void divide(int array[], int left, int right)
{
    if (left == right)
    {
        return;
    }
    else
    {
        int mid = left + (right - left)/2;
        divide(array, left, mid);
        divide(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

void printArray(int array[], int n)
    {
        int i;
        for (i=0; i < n; i++)
        {
        printf("%d ", array[i]);
        printf("\n");
        }
    }

int search(int *array, int n, int spec, int first);

int main(void)
{
    //get an array
    int n = get_int("Size of your array: ");
    int array[n];
    printf("\nInput your elements:  ");
    for (int i = 0; i < n; i++)
    {
        array[i] = get_int(" ");
    }

int first = 0;

    // sort the array
    divide(array, 0, n-1);

    //print sorted
    printArray(array, n);

    // getting number to search for

    int spec = get_int("Search for:  ");

    if (search(array, n, spec, first) == 1)
    {
        printf("There is no such number in the array\n");
        return 1;
    }
    else
    {
        int output = search(array, n, spec, first);
        printf("This number is the %i-th in the array. Its index is %i\n", output+1, output);
        return 0;
    }
}

int search(int *array, int n, int spec, int first)
{
    int mid = (first + n -1)/2;

    if(mid == 0 || mid == n-1)
    {
        if (array[mid] == spec)
        {
            return mid;
        }
        else
        {
            return 1;
        }
    }
    else

    if (array[mid] == spec)
    {
        return mid;
    }
    else if(array[mid] > spec)
    {
        return search(array, n = mid, spec, first);
    }
    else
    {
        return search(array, n, spec, first = (mid + 1));
    }
}
