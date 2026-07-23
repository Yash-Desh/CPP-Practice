// Author : Yash Deshpande
// Date : 23-07-2026
// Tutor : Claude Opus 4.8

#include <bits/stdc++.h>
using namespace std;

/*
This file covers: Comparators defined inside classes & which fix to use when.

THE CORE PROBLEM: the hidden 'this'
A non-static member function has an invisible first parameter 'this'. So a
member  bool cmp(int a, int b)  is really  cmp(MyClass* this, int a, int b) ,
i.e. 3 arguments. std::sort wants to call cmp(a, b) with exactly 2 args, so the
types don't match and you get a compile error.

There are 3 fixes:
  Fix-1: make the member function 'static'  (no 'this' -> plain 2-arg function)
  Fix-2: functor -> a struct/class with operator()  (does NOT need static)
  Fix-3: lambda  (an anonymous functor, no class member at all)
*/


// ---------------- Fix-1: static member function ------------------------- //
// A static member function has no 'this', so it is just a plain 2-arg function.
// This is the usual answer to "why won't my LeetCode comparator compile?".
class SolutionStatic {
public:
    static bool cmp(int a, int b) {
        return a > b;               // descending
    }

    void run(vector<int> v) {
        sort(v.begin(), v.end(), cmp);      // OK: static -> function pointer
        for(int &x : v) cout << x << " ";
        cout << endl;
    }
};


// ---------------- Fix-2: functor (operator()) -------------------------- //
// You pass an INSTANCE. Here 'this' points to the comparator object itself,
// which is fine - sort just calls object(a, b). Does NOT need static.
// This is ALSO the form needed by set / map / priority_queue, because those
// take a comparator TYPE as a template argument (not a callable value).
struct Cmp {
    bool operator()(int a, int b) const {
        return a > b;               // descending
    }
};


// ---------------- Fix-3: lambda ---------------------------------------- //
// Often the cleanest. A lambda is really an anonymous functor, so it sidesteps
// the whole 'this' issue. Shown inline in main().


int main() {
    // ---- Fix-1: static member function ----
    SolutionStatic sol;
    sol.run({12, 4, 64, 31, 105, -13, 9});

    // ---- Fix-2: functor passed as an INSTANCE to sort ----
    vector<int> v = {12, 4, 64, 31, 105, -13, 9};
    sort(v.begin(), v.end(), Cmp());        // pass an instance
    for(int &x : v) cout << x << " ";
    cout << endl;

    // ---- Fix-2: functor as a TYPE for ordered containers / heaps ----
    priority_queue<int, vector<int>, Cmp> pq;   // type, not instance
    set<int, Cmp> s = {12, 4, 64, 31, 105, -13, 9};
    for(int x : s) cout << x << " ";
    cout << endl;

    // ---- Fix-3: lambda ----
    vector<int> v2 = {12, 4, 64, 31, 105, -13, 9};
    sort(v2.begin(), v2.end(), [](int a, int b){ return a > b; });
    for(int &x : v2) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Note (Claude Opus 4.8, 2026-07-23):

Q: Does a comparator defined in a class have to be static?
   Only when it's a MEMBER FUNCTION passed to an algorithm - because of the
   hidden 'this'. A functor (operator()) or a lambda does not need static.

   | Form                              | Must be static? |
   | Member function passed to sort    | Yes             |
   | Free (non-member) function        | N/A (no 'this') |
   | Functor (operator())              | No              |
   | Lambda                            | No              |


Q: Can Fix-1 (static member function) be used in EVERY case?
   No. It works for the ALGORITHM family that takes a callable VALUE, but not
   where a container wants a comparator TYPE.

   Works directly (comparator passed as a runtime argument):
       sort, stable_sort, nth_element, max_element, ...   -> static is fine

   Does NOT work directly (comparator is a template TYPE parameter):
       set<int, Cmp>, map<int, string, Cmp>,
       priority_queue<int, vector<int>, Cmp>
   A static function is a value/pointer, not a type, so it can't go in the <>.
   You'd need a functor TYPE (Fix-2), OR force the pointer type in - ugly:
       set<int, bool(*)(int,int)> s(cmp);
       priority_queue<int, vector<int>, bool(*)(int,int)> pq(cmp);

   Rule of thumb: for sort-style algorithms, a static member fn is a good
   default. For set / map / priority_queue, prefer a functor or a lambda -
   that's the form those templates actually want.
*/
