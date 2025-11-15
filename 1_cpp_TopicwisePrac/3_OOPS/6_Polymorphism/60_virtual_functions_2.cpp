// Author : Yash Deshpande 
// Date : 26-02-2022

#include <iostream>
using namespace std;

class CWH     // CWH ==> Code With Harry
{
    protected:
        string title;
        float rating;
    public:
        CWH(string s, float r)
        {
            title =  s;
            rating = r;
        }
        
        virtual void display(){}
};

class CWHVideo: public CWH      // // CWHVideo ==> Code With Harry Video tutorial
{
    float videoLength;
    public:
        CWHVideo(string s, float r, float vl): CWH(s, r){
            videoLength = vl;
        }
        void display(){
            cout<<"This is an amazing video with title "<<title<<endl;
            cout<<"Ratings: "<<rating<<" out of 5 stars"<<endl;
            cout<<"Length of this video is: "<<videoLength<<" minutes"<<endl;
        }
}; 
   
class CWHText: public CWH     // CWHText ==> Code With Harry Text tutorial
{
    int words;
    public:
        CWHText(string s, float r, int wc): CWH(s, r){
            words = wc;   // wc ==> Word count
        }
     void display(){
      cout<<"This is an amazing text tutorial with title "<<title<<endl;
      cout<<"Ratings of this text tutorial: "<<rating<<" out of 5 stars"<<endl;
      cout<<"Number of words in this text tutorial is: "<<words<<" words"<<endl;
         }
};

int main()
{
    string title;
    float rating, vlen;
    int words;

    // for Code With Harry Video
    title = "Django tutorial";
    vlen = 4.56;
    rating = 4.89;
    CWHVideo djVideo(title, rating, vlen);  // djvideo ==> django video

    // for Code With Harry Text
    title = "Django tutorial Text";
    words = 433;
    rating = 4.19;
    CWHText djText(title, rating, words);    // djtext ==> django Text

    CWH* tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;

    tuts[0]->display();
    tuts[1]->display();
    
    return 0;
}
/*

##############################################Extra Notes#####################################################s

1. A member function in the base class which is declared using virtual keyword is called virtual functions. 

2. They can be redefined in the derived class. 

3.  virtual functions are used to implement run-time polymorphism.

4. If we don’t use the “virtual” keyword with the “display” function of the base class then the “display” function 
   of the base class will run.

5. We have used the “virtual” keyword with the “display” function of the base class to make is a virtual function 
   so when the display function is called by using the base class pointer the display function of the derived class 
   will run because the base class pointer is pointing to the derived class object.

6. Rules for virtual functions

    1. They cannot be static
    2. They are accessed by object pointers
    3. Virtual functions can be a friend of another class
    4. A virtual function in the base class might not be used.
    5. If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class


*/