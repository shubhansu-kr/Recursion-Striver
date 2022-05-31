// https://leetcode.com/problems/combination-sum/

// Given an array of distinct integers candidates and a target
// integer target, return a list of all unique combinations of
// candidates where the chosen numbers sum to target. You may return
// the combinations in any order.

// The same number may be chosen from candidates an unlimited number
// of times. Two combinations are unique if the frequency of at least
// one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum
// up to target is less than 150 combinations for the given input.

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> v;
        cSum(res, candidates, v, target);
        return res;
    }

    void cSum(vector<vector<int>> &res, vector<int> &candidates, vector<int> &v, int target, int i = 0)
    {
        if (i >= candidates.size())
        {
            if (target == 0)
            {
                res.emplace_back(v);
            }
            return;
        }
        if (candidates[i] <= target)
        {
            target -= candidates[i];
            v.emplace_back(candidates[i]);
            cSum(res, candidates, v, target, i);
            v.pop_back();
            target += candidates[i];
        }

        cSum(res, candidates, v, target, i + 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}