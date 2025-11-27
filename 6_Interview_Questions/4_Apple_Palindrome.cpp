#include <iostream>
#include <vector>
using namespace std;




// Your previous Plain Text content is preserved below:

// This is just a simple shared plaintext pad, with no execution capabilities.

// When you know what language you'd like to use for your interview,
// simply choose it from the dots menu on the tab, or add a new language
// tab using the Languages button on the left.

// You can also change the default language your pads are created with
// in your account settings: https://app.coderpad.io/settings

// Enjoy your interview!

// Given a string `s` (which may contain spaces and mixed-case letters), determine whether its letters can be rearranged into a palindrome. If it can be rearranged into a palindrome, return `True`. 

// If it cannot, return the minimum number of letters you'd need to remove from the original string to make it possible.

//   s = "aabbc"` -> `True` (can be rearranged to "abcba")
//   s = "aabbcd"` -> `1` (remove 'c' or 'd' to get "aabbd" or "aabbc")
//   s = "racecar"` -> `True`
//   s = "ecarrac" -> True
//   s = "no lemon, no melon"` -> `True`
//   s = "abcd" -> false 

/*
    Ignore spaces: Only consider alphabetic characters.
    Case-insensitive: Treat 'A' and 'a' as the same letter (normalize to lowercase).
    We don't care about constructing the actual palindrome, just its possibility and the minimum removals. 
*/

// abba -> true
// abab -> true;

// ooboo
// abBa -> 
string simplify (string str) {
  string ans = "";
  for(int i=0; i<str.size(); i++) {
    if(str[i] >= 'a' && str[i] <= 'z') {
      ans += str[i];
    }
    else if(str[i] >= 'A' && str[i] <= 'Z') {
      char ch = str[i]-'A'+'a';
      ans += ch;
    }
  }
  return ans;
}

//  nolemonnomelon

bool isPalindrome(string str) {
  // create copy string without any spaces & with all letters converted to lowercase.
  
  string copy_str = simplify(str);
  cout<< copy_str << endl;

  int l = 0;
  int h = copy_str.size()-1;

  while(l < h) {
    if(copy_str[l] != copy_str[h]) {
      return false;
    }
    cout<<copy_str[l] << " " << copy_str[h]<< endl;
    l++;
    h--;
  }
  return true;
}

// abaccc
// a = 2 b = 1 c = 3

bool func(string str) {
  int hash[26] = {0};
  string copy_str = simplify(str);
  for(int i =0; i < copy_str.size(); i++) {
    hash[copy_str[i]-'a']++;
  }

  int cnt_odd = 0;
  for(int i=0; i<26; i++) {
    if(hash[i]%2 != 0) {
      cnt_odd++;
    }
  }
  
  if (cnt_odd > 1) {
    return false;
  }
  else {
    return true;
  }

}

// To execute C++, please define "int main()"
int main() {
//   string s = "aabbc"; // -> `True` (can be rearranged to "abcba")
// //   s = "aabbcd"; // -> `1` (remove 'c' or 'd' to get "aabbd" or "aabbc")
// //   s = "racecar"; // -> `True`
// //   s = "ecarrac;" // -> True
// //   s = "no lemon, no melon"; // -> `True`
// //   s = "abcd"; // -> false 

//   // cout << simplify(s1);
//   // if(isPalindrome(s1)) {
//   //   cout << "Yes\n";
//   // }
//   // else {
//      cout << "No\n";
//   }

  // vector<string> check = {}

  string s = "ecarrac";
  if(func(s)) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }

  s = "racecAr";
  if(func(s)) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }

  s = "nO leMon, no melon";
  if(func(s)) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }

  s = "aaabbbccddee";
  if(func(s)) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
  return 0;
}