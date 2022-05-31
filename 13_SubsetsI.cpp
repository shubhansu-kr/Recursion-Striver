// https://leetcode.com/problems/subsets/

// Given an integer array nums of unique elements, return all possible
// subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution
// in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Time Complexity : 2^N * N
    // Space Complexity : 2^N
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sub(nums, temp, ans);
        return ans;
    }
    void sub(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int i = 0)
    {
        if (i >= nums.size())
        {
            ans.emplace_back(temp);
            return;
        }
        temp.emplace_back(nums[i]);
        sub(nums, temp, ans, i + 1);
        temp.pop_back();
        sub(nums, temp, ans, i + 1);
    }
};

class Solution
{
    // Time Complexity : 2^N * N
    // Space Complexity : 2^N
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        // Number of subsets = 2^n -1
        int N = 1 << nums.size();
        for (int i = 0; i < N; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i & (1 << j))
                {
                    temp.emplace_back(nums[j]);
                }
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}