// Author: Yash Deshpande
// Date  : 18-08-2026
// Interviwee: Vedant Paranjpe
// Interviewer: Samarth Narang (Qualcomm)
// Link  : https://gist.github.com/VedantParanjape/063b819626d1c2fbc05df2be119ed5fa

#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

class Solution {
public:
    // Return floor(sqrt(x))
    int mySqrt(int x) {
        // TODO: implement
           return -1;
    }
};

static void runOne(int x, int expected) {
    Solution s;
    int got = s.mySqrt(x);
    if (got != expected) {
        std::cerr << "FAIL: x=" << x << " expected=" << expected << " got=" << got << "\n";
        std::exit(1);
    }
}

int main() {
    return 0;
}
