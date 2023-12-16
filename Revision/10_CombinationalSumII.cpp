// https://leetcode.com/problems/combination-sum-ii/

#include <bits/stdc++.h>
using namespace std ;


class Solution {
    // solution for repetetive elements of combinational sum I - WA 
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, set<vector<int>> &st, vector<int> &sub, int k, int i){
        if (k < 0) return;
        if (i < 0 || k == 0) {
            if (k == 0) {
                sort(sub.begin(), sub.end());
                if (!st.count(sub)){
                    ans.emplace_back(sub);
                    st.insert(sub);
                }
            }
            return;
        }

        sub.emplace_back(nums[i]);
        solve(nums, ans, st, sub, k-nums[i], i-1);
        sub.pop_back();
        solve(nums, ans, st, sub, k, i-1);
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        vector<vector<int>> ans;
        set<vector<int>> st;

        int n = candidates.size();

        solve(candidates, ans, st, sub, target, n-1);
        return ans;
    }
};

int main () {
    
    return 0;
}