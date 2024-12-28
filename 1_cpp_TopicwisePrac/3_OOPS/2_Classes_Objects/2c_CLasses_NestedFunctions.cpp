// Author : Yash Deshpande
// Date : 27-01-2022

// Nesting of member functions

#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
    string s;
    void chk_bin(void);

public:
    void read(void);
    void ones_compliment(void);
    void display(void);

    // 2 different ways to display a string data
    void display2(void)
    {
        cout<<s;
    }
};

void binary::read(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s;
}

void binary::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary  :: ones_compliment(void)
{
    chk_bin();   // This is an example of nesting of member functions in classes
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
       else
        {
            s.at(i) = '0';
        }
    }
}

void binary::display(void)
{
    cout<<"Displaying your binary number"<<endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout<<endl;
}

int main()
{
    binary b;
    b.read();
    // b.chk_bin();  --> It is a private function
    b.display();
    b.ones_compliment();
    b.display();
    b.display2();
    return 0;
}

/*

##############################################Extra Notes#####################################################

OOPs - Classes and objects

1. C++ --> initially called --> C with classes by stroustroup

2. class --> extension of structures (in C)

3. structures had limitations
     - members are public
     - No methods

4. classes --> structures + more

5. classes --> can have methods and properties

6. classes --> can make few members as private & few as public

7. structures in C++ are typedefed

8. u can declare objects along with the class declarion like this:

class Employee
    {

        // Class definition

    } harry, rohan, lovish;

9. harry.salary = 8; --> makes no sense if salary is private

10. If one member function is called inside the other member function of the same class it is called nesting of a 
    member function

*/