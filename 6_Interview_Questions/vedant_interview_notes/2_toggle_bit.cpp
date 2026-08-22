// Author: Yash Deshpande
// Date  : 18-08-2026
// Interviwee: Vedant Paranjpe
// Interviewer: Abhikrant Sharma (Qualcomm)
// Link  : https://gist.github.com/VedantParanjape/9b9a6060570a86bf8e714ce74b5602bf

#include <iostream>
#include <cstdint>

// Given a number N, Toggle Kth bit of a number N
// For example:
// Enter number: 7 :: 111
// Enter k: 3
// Original number before toggling: 7
// New number after toggling: 3
 
uint32_t toggle(uint32_t n , int k) {
    if (k < 0)
        return n;
    
    k = k % 31;
    // bit = 1
    uint32_t bit = 1 << k;
    // 111 | 100 -> 111 -> 011
    uint32_t ret = n ^ bit;
    return ret;
}

// std::string {
//     char c[n];
//     int size;
// }

/*
-----------------------------------------------------------------------------------------------------------------------------
[Claude Opus 5]
The documented example doesn't match the code

  toggle(7,3) = 15    // the comment claims 3

  The comment block is using 1-indexed bit positions (k=3 → the 3rd bit from the right = 0b100 = 4, and 7 ^ 4 = 3). 
  The code is 0-indexed (1 << 3 = 8, and 7 ^ 8 = 15).

  Pick one and make the comment agree. 0-indexed is the conventional choice and is what the code does — so the example 
  should read Enter k: 2 → New number: 3. In a real interview this is the first thing to clarify out loud before writing code.

  Also, // 111 | 100 -> 111 -> 011 says | but the code does ^, and | can't produce 011 from 111 anyway.

  k = k % 31 is the real bug

  Two separate problems, both of which an interviewer will pounce on:

  k=30 -> k%31=30  toggle(0,k)=0x40000000
  k=31 -> k%31= 0  toggle(0,k)=0x00000001   // bit 31 is unreachable!
  k=32 -> k%31= 1  toggle(0,k)=0x00000002   // silently wrong

  1. Bit 31 can never be toggled. A uint32_t has 32 bits (0–31), so the modulus is off by one. It should be 32, not 31.
  2. Masking at all is the wrong policy. k=32 isn't a request to toggle bit 0 — it's a caller bug. Silently remapping it turns a detectable error into a
  plausible-looking wrong answer. Reject it (return n, assert, or take an out-param error code) the same way the k < 0 branch already does.

  % 32 would at least be self-consistent, but for an interview answer, validate and reject.

  1 << k has the wrong type

  The literal 1 is int, not unsigned. At k = 31 you shift into the sign bit of a signed 32-bit type — undefined behavior in C and in C++ before C++20
  (C++20 redefined shifts in terms of modular arithmetic, so it's well-defined there). UBSan confirms it flags this in C mode:

  runtime error: left shift of 1 by 31 places cannot be represented in type 'int'

  It happens to produce the right bit pattern on gcc/x86 because the conversion to uint32_t wraps as you'd hope, but you don't want to defend that in an
  interview. Write 1u << k or uint32_t{1} << k.

  Corrected version

  // Toggle the k-th bit (0-indexed, LSB = bit 0) of n.
  // Returns n unchanged if k is out of range.
  uint32_t toggle(uint32_t n, int k) {
      if (k < 0 || k >= 32)          // no silent wraparound
          return n;
      return n ^ (1u << k);          // 1u, not 1 — avoids shifting into a sign bit
  }

  For the documented example with 0-indexing: toggle(7, 2) → 0b111 ^ 0b100 = 0b011 = 3.

  A static_assert-free generic form worth mentioning if the interviewer pushes on portability:

  if (k < 0 || static_cast<unsigned>(k) >= std::numeric_limits<uint32_t>::digits)

  Minor

  The trailing std::string sketch (lines 29–32) looks like scratch from a different part of the conversation. Also, unlike 1_floor-sqrt.cpp, this file has
  no main or test harness, so it won't link as a standalone translation unit.

*/