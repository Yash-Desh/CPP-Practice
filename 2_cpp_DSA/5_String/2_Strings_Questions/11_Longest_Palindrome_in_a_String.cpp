#include <bits/stdc++.h>
using namespace std;

// Brute force : TLE
// TC = O(N^3)
bool isPalindrome(string test)
    {
        int i=0;
        int j = test.size()-1;
        while(i < j)
        {
            if(test[i] != test[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    

    string longestPalin (string S) {
        // code here
        int n = S.size();
        string ans ="";
        int ansLen = INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                string temp = S.substr(i,j);
                int tempLen = temp.size();
                if(isPalindrome(temp) && temp.size() > ansLen)
                {
                    ans = temp;
                    ansLen = temp.size();
                }
            }
        }
        return ans;
    }



// // Better Approach  : AC
// // TC = O(N^2) 
// string longestPalin (string S) {
//         // code here
//         int n = S.size();
//         int startIndex =0;
//         int ansSize = 1;
        
//         int l, h;
//         for(int i=1; i<n; i++)
//         {
//             // even substring
//             l = i-1;
//             h = i;
//             while(l >= 0 && h < S.size() && S[l] == S[h])
//             {
//                 if(h-l +1 > ansSize)
//                 {
//                     startIndex = l;
//                     ansSize = h-l+1;
//                 }
//                 h++;
//                 l--;
//             }
            
//             // odd substring
//             l = i-1;
//             h = i+1;
//             while(l >= 0 && h < S.size() && S[l] == S[h])
//             {
//                 if(h-l +1 > ansSize)
//                 {
//                     startIndex = l;
//                     ansSize = h-l+1;
//                 }
//                 h++;
//                 l--;
//             }
//         }
//         return S.substr(startIndex, ansSize);
//     }

int main()
{
    string S = "aaaabbaa";
    cout<<longestPalin(S)<<endl;
    
    return 0;
}