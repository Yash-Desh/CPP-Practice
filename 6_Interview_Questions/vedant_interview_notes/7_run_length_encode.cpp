// Author: Yash Deshpande
// Date  : 18-08-2026
// Interviwee: Vedant Paranjpe
// Interviewer: Abhishek Sudhakaran (Olix)
// Link  : https://gist.github.com/VedantParanjape/67d936168489fd80f44fa2c7e8eee314


// Implement a naive run-length encoding in the function compress 
// Example 1: aabbbaeefff -> 2a3b1a2e3f 
// Example 2: zzjdeffttt -> 2z1j1d1e2f3t 

#include <string>
#include <iostream>

std::string compress(const std::string& seq) {
    std::string result;
    char curr = seq[0];
    int counter = 0;
    for (int i = 0; i < seq.length(); i++) {
        if (curr == seq[i]) {
            counter++;
            curr = seq[i];
        } else {
            result += std::to_string(counter);
            result += curr;
            curr = seq[i];
            counter = 1;
        }
    }
    result += std::to_string(counter);
    result += curr;
    
    return result;
}
    
int main() {
    const auto seqs = {"aabbbaeefff", "zzjdeffttt","","abc"};

    for (const auto& seq: seqs) {
        std::cout << seq << " -> " << compress(seq) << "\n";
    }
}