// Author : Yash Deshpande
// Date : 15-03-2025

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary_search(int *arr, int size, int to_find)
{
    int l = 0;
    int h = size - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == to_find)
        {
            return mid;
        }

        else if (arr[mid] > to_find)
        {
            h = mid - 1;
        }

        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(int *arr, int to_find, int l, int h)
{
    // base case
    if (l > h)
        return -1;

    int mid = l + (h - l) / 2;

    if (arr[mid] == to_find)
        return mid;

    else if (arr[mid] > to_find)
    {
        return binary_search_recursive(arr, to_find, l, mid - 1);
    }

    else
        return binary_search_recursive(arr, to_find, mid + 1, h);
}

void selection_sort(int *arr, int n)
{
    int min_element = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < n - 1; i++)
    {
        min_element = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min_element)
            {
                min_element = arr[j];
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swap_flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap_flag = true;
            }
        }
        if (!swap_flag)
        {
            return;
        }
    }
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int *arr, int l, int h)
{
    int mid = l + (h - l) / 2;

    int len1 = mid - l;
    int len2 = h - mid + 1;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k = l;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k++];
    }

    k = l;
    int k1 = 0;
    int k2 = 0;
    while (k1 < len1 && k2 < len2)
    {
        if (arr1[k1] < arr2[k2])
        {
            arr[k++] = arr1[k1++];
        }
        else
        {
            arr[k++] = arr2[k2++];
        }
    }
    while (k1 < len1)
    {
        arr[k++] = arr1[k1++];
    }

    while (k2 < len2)
    {
        arr[k++] = arr2[k2++];
    }

    delete [] arr1;
    delete [] arr2;
}

void merge_sort(int *arr, int l, int h)
{
    // base case
    if (l >= h)
    {
        return;
    }
    int mid = l + (h - l) / 2;

    merge_sort(arr, l, mid - 1);
    merge_sort(arr, mid, h);

    merge(arr, l, h);
}


int find_pivot(int *arr, int l, int h)
{
    int pivot_index = l;
    int pivot_element = arr[l];

    int cnt=0;
    for(int i=l+1; i<=h; i++)
    {
        if(arr[i] <= pivot_element)
        {
            cnt++;
        }
    }

    pivot_index += cnt;

    swap(arr[l], arr[pivot_index]);

    int low = l;
    int high = h;

    while(low < pivot_index && high > pivot_index)
    {
        while(arr[low] <= arr[pivot_index])
        {
            low++;
        }

        while(arr[high] > arr[pivot_index])
        {
            high--;
        }
        if(low < pivot_index && high > pivot_index)
        {
            swap(arr[low], arr[high]);
        }
    }
    return pivot_index;
}

void quick_sort(int *arr, int l, int h)
{
    // base case 
    if(l >= h)
        return;

    int pivot = find_pivot(arr, l, h);

    quick_sort(arr, l, pivot-1);

    quick_sort(arr, pivot+1, h);
}


int main()
{
    int arr[10] = {12, 25, 45, 64, 112, 150, 165, 212, 403, 777};
    cout << binary_search(arr, 10, 166);
    cout << binary_search_recursive(arr, 166, 0, 9);
    return 0;
}