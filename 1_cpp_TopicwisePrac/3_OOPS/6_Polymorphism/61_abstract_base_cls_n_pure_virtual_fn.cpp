// Author : Yash Deshpande 
// Date : 28-02-2022

#include <iostream>
using namespace std;

class CWH{
    protected:
        string title;
        float rating;
    public:
        CWH(string s, float r){
            title =  s;
            rating = r;
        }
        virtual void display()=0;  // Do nothing function ==> Pure Virtual Funtion
};
class CWHVideo: public CWH
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
class CWHText: public CWH
{
    int words;
    public:
        CWHText(string s, float r, int wc): CWH(s, r){
            words = wc;
        }
     void display(){
      cout<<"This is an amazing text tutorial with title "<<title<<endl;
      cout<<"Ratings of this text tutorial: "<<rating<<" out of 5 stars"<<endl;
      cout<<"No of words in this text tutorial is: "<<words<<" words"<<endl;
         }
};

int main()
{
   string title;
    float rating, vlen;
    int words;

    // for Code With Harry Video
    title = "Django Video Tutorial";
    vlen = 4.56;
    rating = 4.89;
    CWHVideo djVideo(title, rating, vlen);

    // for Code With Harry Text
    title = "Django Text Tutorial";
    words = 433;
    rating = 4.19;
    CWHText djText(title, rating, words);

    CWH* tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;

    tuts[0]->display();
    cout<<""<<endl;
    tuts[1]->display(); 
    return 0;
}
/*

##############################################Extra Notes#####################################################s

1. Pure virtual function is a function that doesn’t perform any operation and the function is declared by assigning the value 0 
   to it. 

2. Pure virtual functions are declared in abstract classes.

3. Abstract base class is a class that has at least one pure virtual function in its body. The classes which are inheriting the 
   base class need to override the virtual function of the abstract class otherwise compiler will throw an error.

4. The class “CHW” has a pure virtual function void “display” which is declared by 0. The main thing to note here is that as 
   the “display” function is a pure virtual function it is compulsory to redefine it in the derived classes.

*/