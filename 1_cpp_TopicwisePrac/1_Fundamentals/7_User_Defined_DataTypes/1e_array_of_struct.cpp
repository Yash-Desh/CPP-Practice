// Author : Yash Deshpande
// Date : 22-03-2022

#include <iostream>
using namespace std;


/*

Structure based on "Playing card" which have 3 properties

1. face_val stands for the face value of the card like 'Ace = 1',2,3,4,5,...,10, Jack = 11, Queen = 12, King = 13

2. Shape stands for "Club" = 0, "Spade" = 1, "Diamond" = 2, "Heart" = 3

3. Color stands for "Black" = 0, "Red" = 1

*/

struct Card{
    int face_val;
    int shape;
    int color;
};

int main()
{
    // Declare & initialize a struct for a single card
    struct Card c;
    c.face_val = 1;
    c.shape = 0;
    c.color = 0;

    // A deck of cards has 52  cards & can be defined using an "array of structure"

    struct Card deck[52] = {{1,0,0},{2,0,1},{10,2,0}};
    
    cout<<deck[0].face_val<<endl;
    cout<<deck[0].shape<<endl;
    




    return 0;
}