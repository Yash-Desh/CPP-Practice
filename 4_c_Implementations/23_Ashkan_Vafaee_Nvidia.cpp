#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Q what are the possible issues with this code ? 

class Math 
{
public:
    Math(int32_t* x, u_int8_t* p) 
    {
        m_x = new int32_t(*x);
        m_p = new u_int8_t(*p);
    }

    int32_t power() 
    {
        int32_t pow = 1;
        for(u_int8_t i=0; i < *m_p; i++) {
            pow = pow * *m_x;
        }
        return pow;
    }

private:
    int32_t *m_x;
    u_int8_t *m_p;
};

int main() {
    int32_t* x;
    u_int8_t* p;
    Math m(x, p);
    cout << "Power is:" << m.power() << endl;

    return 0;
}

/*

Add destructor, copy/move ctor, and copy/move assignment (Rule of 5).

Check for nullptr inputs before dereferencing.

Handle new throwing std::bad_alloc.

overflow

*/