// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
public:
    int solve(vector<int> &nums, int target, int i){
        if (i < 0) {
            return target == 0;
        }

        return solve(nums, target, i-1) + solve(nums, target-nums[i], i-1);
    }

    int numSubseq(vector<int>& nums, int target) {
        return solve(nums, target, nums.size()-1);
    }
};

class Solution {
public:
    void solve(vector<int> &nums, int &target, int &ans, int &sum, int i){
        if (i < 0) {
            if (sum == target){
                ++ans;
            }
            return;
        }

        sum += nums[i];
        solve(nums, target, ans, sum, i-1);
        sum -= nums[i];
        solve(nums, target, ans, sum, i-1);
    }

    int numSubseq(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        int ans = 0;
        solve(nums, target, ans, sum, n-1);
        return ans;
    }
};

int main () {
    
    return 0;
}