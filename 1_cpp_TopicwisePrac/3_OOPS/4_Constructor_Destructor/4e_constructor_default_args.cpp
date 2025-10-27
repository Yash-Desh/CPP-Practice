// Author : Yash Deshpande
// Date : 31-01-2022

#include<iostream>
using namespace std;

class Simple{
    int data1;
    int data2;
    int data3;

    public:
        Simple(int a, int b=9, int c=8){
            data1 = a;
            data2 = b;
            data3 = c;
        }

        void printData();

};

void Simple :: printData(){
    cout<<"The value of data1, data2 and data3 is "<<data1<<", "<< data2<<" and "<< data3<<endl;
}

int main(){
    Simple s1(12, 13);
    s1.printData();         // The value of data1, data2 and data3 is 12, 13 and 8

    Simple s2(12);
    s2.printData();         // The value of data1, data2 and data3 is 12, 9 and 8
    return 0;
}
