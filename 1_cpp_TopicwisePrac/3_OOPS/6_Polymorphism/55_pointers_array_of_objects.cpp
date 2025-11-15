// Author : Yash Deshpande 
// Date : 22-02-2022

#include<iostream>
using namespace std;

class ShopItem
{
    int id;
    float price;
    
    public:
        void setData(int a, float b){
            id = a;
            price = b;
        }
        void getData(void){
            cout<<"Code of this item is "<< id<<endl;
            cout<<"Price of this item is "<<price<<endl;
        }
};

int main(){
    int size = 3;
    ShopItem *ptr = new ShopItem [size];
    ShopItem *ptrTemp = ptr;  // Pointer for the 2nd for loop
    
    int p, i;
    float q;
    
    for (i = 0; i < size; i++)
    {
        cout<<"Enter Id and price of item "<< i+1<<endl;
        cin>>p>>q;
        // (*ptr).setData(p, q);
        ptr->setData(p, q);
        ptr++; 
    }

    for (i = 0; i < size; i++)
    {
        cout<<"Item number: "<<i+1<<endl;
        ptrTemp->getData();
        ptrTemp++;
    }
    
    
    return 0;
}
/*

##############################################Extra Notes#####################################################s

1. Array of objects can be defined as an array that’s each element is an object of the class. 

2. In the first “for” loop we are incrementing the value of the pointer “ptr” because it is pointing to the address of 
   array of objects and when loop will run every time the function “setdata” will be called by the different object. 
   If we don’t increment the value of the pointer “ptr” then each time function “setdata” will be called by the same object. 

3. Likewise in the second loop we are incrementing the pointer “ptrTemp” so that the function “getdata” could be called by 
   each object in the array.

*/
 