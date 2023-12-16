// SubSequence With sum k

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    void solve(vector<int> &nums, int &k, vector<vector<int>> &ans, vector<int> &sub, int &sum, int i){
        if (i < 0) {
            if (sum == k) {
                ans.emplace_back(sub);
            }
            return;
        }

        sub.emplace_back(nums[i]);
        sum += nums[i];
        solve(nums, k, ans, sub, sum, i-1);
        sum -= nums[i];
        sub.pop_back();
        solve(nums, k, ans, sub, sum, i-1);
    }

    vector<vector<int>> subSequenceWithSumK(vector<int> &nums, int k) {
        vector<vector<int>> ans;
        vector<int> sub;
        int sum = 0, n = nums.size();

        solve(nums, k, ans, sub, sum, n-1);

        return ans;
    }
};

int main () {
    
    return 0;
}