// Print all subsequence

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &sub, int i){
        if (i < 0) {
            ans.emplace_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        solve(nums, ans, sub, i-1);
        sub.pop_back();
        solve(nums, ans, sub, i-1);
    }

    vector<vector<int>> subsequence(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> sub;
        int n = nums.size();

        solve(nums, ans, sub, n-1);

        return ans;
    }
};

int main () {
    
    return 0;
}