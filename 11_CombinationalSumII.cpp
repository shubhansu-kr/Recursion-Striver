// https://leetcode.com/problems/combination-sum-ii/

// Given a collection of candidate numbers (candidates) and a
// target number (target), find all unique combinations in candidates
// where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        comb(candidates, target, res, v);
        return res;
    }

    void comb(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &v, int i = 0)
    {
        if (target == 0)
        {
            res.push_back(v);
            return;
        }
        for (int j = i; j < candidates.size(); ++j)
        {
            if (candidates[j] > target)
            {
                break;
            }
            if (j > i && candidates[j] == candidates[j - 1])
            {
                // Don't pick 
                continue;
            }
            else
            {
                // Pick
                v.push_back(candidates[j]);
                comb(candidates, target - candidates[j], res, v, j + 1);
                v.pop_back();
            }
        }
    }
};

class Solution
{
    // Wrong answer -- Set cant ensure the lexographical order.
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        set<vector<int>> s;
        vector<int> v;
        comb(candidates, target, s, v);
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }

    void comb(vector<int> &candidates, int target, set<vector<int>> &s, vector<int> &v, int i = 0)
    {
        if (i >= candidates.size())
        {
            if (target == 0)
            {
                s.insert(v);
            }
            return;
        }
        if (candidates[i] <= target)
        {
            v.emplace_back(candidates[i]);
            comb(candidates, target - candidates[i], s, v, i + 1);
            v.pop_back();
        }
        comb(candidates, target, s, v, i + 1);
    }
};

class Solution
{
    // Time Limit Exceeded - Wrong answer
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> v;
        cSum(candidates, res, v, target);
        return res;
    }

    void cSum(vector<int> &candidates, vector<vector<int>> &res, vector<int> &v, int target, int i = 0, int sum = 0)
    {
        if (i >= candidates.size() || sum >= target)
        {
            if (sum == target)
            {
            }
            res.emplace_back(v);
            return;
        }
        // take
        sum += candidates[i];
        v.emplace_back(candidates[i]);
        cSum(candidates, res, v, target, i, sum);

        // not take
        sum -= candidates[i];
        v.pop_back();
        cSum(candidates, res, v, target, i, sum);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution obj1;
    vector<int> vec = {10, 1, 2, 7, 6, 1, 5};
    vector<int> v;
    vector<vector<int>> res;
    obj1.cSum(vec, res, v, 8);
    return 0;
}