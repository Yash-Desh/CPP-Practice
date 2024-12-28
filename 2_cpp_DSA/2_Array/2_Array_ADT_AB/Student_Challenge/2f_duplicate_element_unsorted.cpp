// Author : Yash Deshpande
// Date : 16-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;   // Total elements in the array
    int length; // Total values initialized in the array
};

void display(struct Array a)
{
    cout << "Displaying array elements : ";
    for (int j = 0; j < a.length; j++)
    {
        cout << a.A[j] << " ";
    }
    cout << endl;
}

int max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}


// function to find duplicate elements in an unsorted array
void duplicateUnsorted(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {

            for (int j = i + 1; j < arr.length; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if(count > 1)
            {
                cout << arr.A[i] << " is repeated " << count << " times" << endl;
            }
        }
    }
}


// function to find duplicate elements in an unsorted array using hashing
void duplicateUnsortedHash (struct Array arr)
{
    int h = max(arr);
    int H[h+1] = {0};
    for(int i=0; i<arr.length; i++)
    {
        H[arr.A[i]]++;
    }

    for(int i=0; i<=h; i++)
    {
        if(H[i] > 1)
        {
            cout<<i<<" is repeated "<<H[i]<<" times"<<endl;
        }
    }
}

int main()
{
    struct Array arr1 = {{8,3,6,4,6,5,6,8,2,7}, 20, 10};
    display(arr1);

    duplicateUnsorted(arr1);

    cout<<endl<<"Using hashing"<<endl;
    duplicateUnsortedHash(arr1);
    return 0;
}