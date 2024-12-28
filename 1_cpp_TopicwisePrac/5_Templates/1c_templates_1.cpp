// Author : Yash Deshpande
// Date : 19-03-2022

#include <iostream>
using namespace std;

template <class T>
class vector{
    int size;
    public:
        T * arr;
        vector(int m)    // Constructor
        {
            size = m;
            arr = new int [size];
        }
        T dotProduct (vector &v)
        {
            T d = 0;
            for(int i = 0; i<size; i++)
            {
                d += this->arr[i] * v.arr[i];
            }
            return d;
        }

};

int main()
{
    vector<int> v1(3);
    v1.arr[0]= 2;
    v1.arr[1]= 3;
    v1.arr[2]= 1;

    vector<int> v2(3);
    v2.arr[0]= 1;
    v2.arr[1]= 0;
    v2.arr[2]= 4;

    int result = v1.dotProduct(v2);
    cout<<result<<endl;


    return 0;
}