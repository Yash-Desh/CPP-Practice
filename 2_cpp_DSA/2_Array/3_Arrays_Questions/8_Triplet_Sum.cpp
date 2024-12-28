// Author : Yash Deshpande
// Date : 19-08-2022
// Website : Coding Ninjas
// Tutor : Love Babbar Placement series
// Topic : Arrays

// Q. unique triplets that sum to a given value K
//    return all such triplets
//    the given array may have repeated elements

#include <bits/stdc++.h>
using namespace std;

// Brute Approach : Using 3 For loops , TLE
// Store the ans in sets so that there is no repetition of triplets
// time : O(n^3 . log(m))

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    set<vector<int>> ansSet;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == K)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};

                    // sort before insertion into the set
                    // this is to avoid duplication of the same vector
                    // so the ans only contains unique triplets
                    sort(temp.begin(), temp.end());
                    ansSet.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans;
    for (auto it = ansSet.begin(); it != ansSet.end(); it++)
    {
        ans.push_back(*it);
    }
    return ans;
}

// Using hashing

// 1. create a hash map of all the elements
// 2. Run 2 loops to create a combination of every 2 nos
// 3. inside the 2nd loop check if the remnant of the combination
//    is available in the hash map

vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.

    // create a vector to store all the ans
    vector<vector<int>> ans;

    // create a set to store the unique triplets
    set<vector<int>> tripletSet;

    // create a hash map
    map<int, int> hashMap;
    for (int i = 0; i < arr.size(); i++)
    {
        hashMap[arr[i]]++;
    }

    // 2 for loops to create 2 number combinations
    for (int i = 0; i < arr.size(); i++)
    {
        // remove the ith element from the hashMap
        // to prevent selection of the same element
        hashMap[arr[i]]--;
        for (int j = i + 1; j < arr.size(); j++)
        {
            // remove the jth element from the hashMap
            // to prevent selection of the same element
            hashMap[arr[j]]--;

            // find the remainder in the hashMap
            int remainder = K - (arr[i] + arr[j]);
            if (hashMap[remainder] > 0)
            {
                vector<int> temp = {arr[i], arr[j], remainder};

                // sort the vector to prevent duplication
                sort(temp.begin(), temp.end());
                tripletSet.insert(temp);
            }

            // replace the removed element
            hashMap[arr[j]]++;
        }
        // replace the removed element
        hashMap[arr[i]]++;
    }

    for (auto it = tripletSet.begin(); it != tripletSet.end(); it++)
    {
        ans.push_back(*it);
    }
    return ans;
}

// Best Approach : 2 pointer approach(only works on sorted array)
vector<vector<int>> findTriplets(vector<int> num, int n, int K)
{
    vector<vector<int>> res;
    sort(num.begin(), num.end());

    // moves for a
    for (int i = 0; i < (int)(num.size()) - 2; i++)
    {

        if (i == 0 || (i > 0 && num[i] != num[i - 1]))
        {

            int lo = i + 1, hi = (int)(num.size()) - 1, sum = K - num[i];

            while (lo < hi)
            {
                if (num[lo] + num[hi] == sum)
                {

                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[lo]);
                    temp.push_back(num[hi]);
                    res.push_back(temp);

                    while (lo < hi && num[lo] == num[lo + 1])
                        lo++;
                    while (lo < hi && num[hi] == num[hi - 1])
                        hi--;

                    lo++;
                    hi--;
                }
                else if (num[lo] + num[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
    }
    return res;
}

int main()
{

    return 0;
}