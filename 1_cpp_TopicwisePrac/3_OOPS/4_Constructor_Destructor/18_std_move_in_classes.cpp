// Author : Yash Deshpande
// Date   : 23-09-2025
// Tutor  : The Cherno

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
    }

private:
    char *m_Data;
    u_int32_t m_Size;
};

class Entity {
public: 
    Entity(const String &name) : m_Name(name)
    {}

    // Notice the difference here from the last file.
    Entity(String &&name) : m_Name(std::move(name))
    {}

    void printName() {
        m_Name.print();
    }

private:
    String m_Name;
};

int main() {

    Entity entity("String");
    entity.printName();

    String string = "Hello";
    String destination = (String &&)string;

    // is the same as 
    String destination2((String &&)string);

    // but an even better way is
    // String destination3 = std::move(string);
    String destination3(std::move(string));

    return 0;
}