// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &sub, int k, int i) {
        if (k < 0) return;
        if (i < 0) {
            if (k == 0) {
                ans.emplace_back(sub);
            } 
            return;
        }

        sub.emplace_back(nums[i]);
        solve(nums, ans, sub, k-nums[i], i);
        sub.pop_back();
        solve(nums, ans, sub, k, i-1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        int n = candidates.size();

        solve(candidates, ans, sub, target, n-1);
        return ans;
    }
};

int main () {
    
    return 0;
}