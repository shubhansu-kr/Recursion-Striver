// https://leetcode.com/problems/subsets-ii/

// Given an integer array nums that may contain duplicates, return all
// possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
    // Recursion ::
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        sub(nums, res, temp);
        return res;
    }
    void sub(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int i = 0)
    {
        res.emplace_back(temp);
        for (int j = i; j < nums.size(); ++j)
        {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            temp.emplace_back(nums[j]);
            sub(nums, res, temp, j + 1);
            temp.pop_back();
        }
    }
};

class Solution2
{
    // Recursion ::
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        res.emplace_back(temp);
        sub(nums, res, temp);
        sort(res.begin(), res.end());
        return res;
    }
    void sub(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int i = 0)
    {
        if (i >= nums.size())
        {
            return;
        }
        for (int j = i; j < nums.size(); ++j)
        {
            if (j > i && nums[j] == nums[j - 1])
            {
                continue;
            }
            temp.emplace_back(nums[j]);
            res.emplace_back(temp);
            sub(nums, res, temp, j + 1);
            temp.pop_back();
        }
    }
};

class Solution1
{
    // Recursion ::
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        set<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        sub(nums, res, temp);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
    void sub(vector<int> &nums, set<vector<int>> &res, vector<int> &temp, int i = 0)
    {
        if (i >= nums.size())
        {
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        temp.emplace_back(nums[i]);
        sub(nums, res, temp, i + 1);
        temp.pop_back();
        sub(nums, res, temp, i + 1);
    }
};

class Solution
{
    // Powerset Approach
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        set<vector<int>> res;
        for (int i = 0; i < (1 << nums.size()); ++i)
        {
            vector<int> temp;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i & (1 << j))
                {
                    temp.emplace_back(nums[j]);
                }
            }
            sort(temp.begin(), temp.end());
            res.insert(temp);
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {4, 1, 0};
    vector<int> temp;
    set<vector<int>> res;

    Solution1 obj1;
    obj1.sub(nums, res, temp);
    vector<vector<int>> ans(res.begin(), res.end());

    for (auto a : ans)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << "REDO " << endl;

    vector<vector<int>> dup = obj1.subsetsWithDup(nums);
    for (auto a : dup)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}