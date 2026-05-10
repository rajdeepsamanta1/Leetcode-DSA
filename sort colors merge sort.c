#include <stdio.h>#include <stdio.h1 + j];   // ✅ FIX: +1 required

    int i = 0, j = 0, k = left;

    // Merge both arrays
    while (i < n1 && j < n2)
    {
        if (l[i] < r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of l[]
    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }

    // Copy remaining elements of r[]
    while (j < n2)   // ✅ FIX: j<n2 (your code had j<n1 ❌)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}


void mergesort(int arr[], int left, int right)
{
    if (left < right)   // ✅ FIX: use if, not while
    {
        int mid = (left + right) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void sortColors(int* nums, int numsSize)
{
    mergesort(nums, 0, numsSize - 1);
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l[n1], r[n2];

    // Copy data
    for (int i = 0; i < n1; i++)
        l[i] = arr[left + i];

    for (int j = 0; j < n2; j++)

