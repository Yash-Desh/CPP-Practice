// Author : Yash Deshpande
// Date : 4-08-2022
// Tutor : Love Babbar


// ######################################## DISCLAIMER : SKIP THIS PAGE ####################################

// NOTE : THIS STL CONTAINER IS RARELY USED
// DUE TO ITS SIMIILARITY WITH NORMAL STATIC ARRAY
// ITS NOT PREFRRRED
// THIS ARTICLE IS ONLY FOR INFORMATION PURPOSE
// NOT READING THIS PAGE DOES NOT AFFECT YOUR CODING ABILITIES IN ANY WAY

// ##########################################################################################################

#include <iostream>
#include <array>
using namespace std;

int main()
{
    // declaring & initialzing a normal array
    int normalArr [] = {1,2,3};

    // declaring & initializing an STL array
    array <int,4> a = {1,2,3,4};

    // accessing elements , TC = O(1)
    cout<<a[2]<<endl;
    cout<<a.at(2)<<endl;

    // finding if array is empty , TC = O(1)
    cout<<a.empty()<<endl;


    // Getting 1st element , TC = O(1)
    cout<<a.front()<<endl;

    // Getting last element , TC = O(1)
    cout<<a.back()<<endl;


    return 0;
}