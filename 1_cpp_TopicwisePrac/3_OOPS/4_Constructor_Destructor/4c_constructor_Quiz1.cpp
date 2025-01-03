// Author : Yash Deshpande
// Date : 31-01-2022

#include<iostream>
#include<cmath>
using namespace std;

class Point{
    int x, y;
    public:
        friend double distance(Point o1, Point o2);
        Point(int a, int b){
            x = a;
            y = b;
        }

        void displayPoint(){
            cout<<"The point is ("<<x<<", "<<y<<")"<<endl;
        }

};
double square (double n)
{
    return n*n;
}
// Create a function (Hint: Make it a friend function) which takes 2 point objects and computes the distance between 
// those 2 points

double distance(Point o1,Point o2)
{
    double num = square (o1.x-o2.x) + square(o1.y-o2.y); 
    return sqrt (num);
}


// Use these examples to check your code:
// Distance between (1, 1) and (1, 1) is 0
// Distance between (0, 1) and (0, 6) is 5
// Distance between (1, 0) and (70, 0) is 69
int main(){
    Point p(1, 0);
    p.displayPoint();

    Point q(70, 0);
    q.displayPoint();
    
    cout<<"Distance between the points p & q = "<<distance(p,q);
    return 0;

}
