// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// Given a list arr of N integers, print sums of all subsets in it.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Time Complexity : 2^N
    // Space Complexity : N
    // Using Recursion
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        sums(arr, ans);
        return ans;
    }
    void sums(vector<int> &arr, vector<int> &ans, int i = 0, int sum = 0)
    {
        if (i >= arr.size())
        {
            ans.emplace_back(sum);
            return;
        }
        sums(arr, ans, i + 1, sum + arr[i]);
        sums(arr, ans, i + 1, sum);
    }
};

class Solution
{
    // Using PowerSet
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // arr : input array 
        // N : Size of arr(input arrray)
        vector<int> ans;
        for (int i = 0; i < (1 << N); ++i)
        {
            int sum = 0;
            for (int j = 0; j < N; ++j)
            {
                if (i & (1 << j))
                {
                    sum += arr[j];
                }
            }
            ans.emplace_back(sum);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 5;
    cout << (1 << N) << endl; // prints 2^N (2^5 = 32).
    
    return 0;
}