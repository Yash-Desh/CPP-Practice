// Author : Yash Deshpande
// Date : 10-02-2022

#include<iostream>
using namespace std;

/*

Ambiguity Resolution : we created a class “A” and two classes “B” and “C”, are being derived from class “A”. 
                       But once we create a class “D” which is being derived from class “B” and “C”.
                       
                       1. Class “A” is a parent class of two classes “B” and “C”
                       2. And both “B” and “C” classes are the parent of class “D”

The data members and member functions of class “A” will be inherited twice in class “D” because 
class “B” and “C” are the parent classes of class “D” and they both are being derived from class “A”.

So when the class “D” will try to access the data member or member function of class “A” it will cause ambiguity for the compiler 
and the compiler will throw an error.


*/

class Student
{
    protected:
        int roll_no;
    public:
        void set_number(int a){
            roll_no = a;
        }
        void print_number(void){
            cout<<"Your roll no is "<< roll_no<<endl;
        }
};

class Test :virtual public Student   // virtual public <class_name> == public virtual <class_name>
{
    protected:
        float maths, physics;
        public:
            void set_marks(float m1, float m2){
                maths = m1;
                physics = m2;
            }

            void print_marks(void){
                cout << "You result is here: "<<endl
                     << "Maths: "<< maths<<endl
                     << "Physics: "<< physics<<endl;
            }
};

class Sports: public virtual Student  // virtual public <class_name> == public virtual <class_name>
{
    protected:
        float score;
    public:
        void set_score(float sc){
            score = sc;
        }

        void print_score(void){
            cout<<"Your PT score is "<<score<<endl;
        }

};

class Result : public Test, public Sports{
    private:
        float total;
    public:
        void display(void){
            total = maths + physics + score;
            print_number();
            print_marks();
            print_score();
            cout<< "Your total score is: "<<total<<endl;
        }
};
int main(){
    Result harry;
    harry.set_number(4200);
    harry.set_marks(78.9, 99.5);
    harry.set_score(9);
    harry.display();
    return 0;
}

/*

##############################################Extra Notes#####################################################s


1. The virtual base class is a concept used in multiple inheritances to prevent ambiguity between multiple instances.

2. When one class is made virtual then only one copy of its data member and member function is passed to the classes inheriting it. 

3. In our example when we will make class “A” a virtual class then only one copy of the data member and member function will
   be passed to the classes “B” and “C” which will be shared between all classes. 
   This will help to solve the ambiguity.

4. virtual inheritance_mode <class_name> == inheritance_mode virtual <class_name>

*/
