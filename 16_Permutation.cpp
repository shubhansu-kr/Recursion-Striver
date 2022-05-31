// https://leetcode.com/problems/permutations/

// Given an array nums of distinct integers, return all the possible permutations.
// You can return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Swapping the nums
    // Time Complexity : N! * 2k ;
    // Space Complexity : Constant -> Since only answer is taking extra space.
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        swapp(nums, ans);
        return ans;
    }
    void swapp(vector<int> &nums, vector<vector<int>> &ans, int i = 0)
    {
        if (i >= nums.size())
        {
            ans.emplace_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); ++j)
        {
            swap(nums[i], nums[j]);
            swapp(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }
};

class Solution
{
    // Recursive Solution Using unordered_map
    // Time Complexity : N! * N
    // Space Complexity : N(for ds) + N(for map)
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int, int> m;
        permutataion(nums, ds, ans, m);
        return ans;
    }
    void permutataion(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, unordered_map<int, int> &m)
    {
        if (ds.size() >= nums.size())
        {
            ans.emplace_back(ds);
            return;
        }
        for (int j = 0; j < nums.size(); ++j)
        {
            if (m[nums[j]])
            {
                continue;
            }
            ds.emplace_back(nums[j]);
            ++m[nums[j]];
            permutataion(nums, ds, ans, m);
            --m[nums[j]];
            ds.pop_back();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}