// Author : Yash Deshpande
// Date   : 23-09-2025
// Tutor  : The Cherno: https://youtu.be/ehMg6zvXuMY?si=Y1xIA8hzO7DVKatZ

#include <iostream>
#include <cstring>
using namespace std;

class String {
public: 
    String() = default;

    // Parameterized Constructor
    String(const char *string) {
        printf("Created\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    // Copy Constructor
    // Why do we need a copy constructor ?
    // Double Delete called by implicit copy constructor
    String (const String &other) {
        printf("Copied\n");
        m_Size = strlen(other.m_Data);
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    // Move Constructor
    String (String &&other) {
        printf("Moved\n");
        m_Size = strlen(other.m_Data);
        m_Data = other.m_Data;
        
        // Hollow out the older object
        other.m_Data = nullptr;
        other.m_Size = 0;
    }

    // Destructor
    ~String() {
        printf("Destroyed\n");
        delete m_Data;
    }

    void print() {
        for(int i=0; i<m_Size; i++) {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }

private:
    char *m_Data;
    u_int32_t m_Size;
};

// Class to consume our string.
class Entity {
public: 
    // Constructor that can accept both lvalue & rvalue due to const reference
    Entity(const String &name) : m_Name(name)
    {
        // We need a copy constructor for this function to work.
    }

    // Error Case: Calls the copy constructor
    // Entity(String &&name) : m_Name(name)
    // {}

    // Constructor that can accept only rvalue reference;
    Entity(String &&name) : m_Name((String &&)name)
    // Entity(String &&name) : m_Name(std::move(name))      // Equivalent method 
    {}

    void printName() {
        m_Name.print();
    }

private:
    String m_Name;
};

int main() {

    // ###############
    // Example-1 : What happens without a copy constructor
    // ###############
    // Why do we need a copy constructor ? 
    // --> "String" object is being passed into another "String" object to construct Entity, thus implicit copy
    // Comment out the copy & move constructors to see double delete being called.
    Entity entity1("Cherno");                // will implicitly call the String() constructor like shown below
    // Entity entity(String("Cherno"))       // Implicit Conversion covered in explicit_keyword lecture

    
    // ###############
    // Example-2 : What happens with a copy constructor
    // ###############
    // In String Class, Comment out the move constructor to see the copy constructor working properly.
    Entity entity2("Cherno");
    entity2.printName();


    // ###############
    // Example-3 : What happens with a move constructor
    // ###############
    // In Entity Class, Comment out the constructor which accepts only rvalues, 
    Entity entity2("Cherno");
    entity2.printName();
    return 0;
}