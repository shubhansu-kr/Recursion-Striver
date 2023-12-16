// Reverse an array using recursion

#include <bits/stdc++.h>
using namespace std ;

class Solution1{
    // Inplace Swapping
public: 
    void solve(vector<int> &nums, int i = 0) {
        if (i > nums.size()/2) {
            return;
        }
        swap(nums[i], nums[nums.size()-i-1]);
        solve(nums, i+1);
    }

    vector<int> reversArr(vector<int> &nums){
        solve(nums);
        return nums;
    }
};

class Solution{
    // BruteForce: Using additional array and backtrack
public: 
    void solve(vector<int> &nums, vector<int> &ans, int i = 0) {
        if (i >= nums.size()) {
            return;
        }
        int x = nums[i];
        solve(nums, ans, i+1);
        ans.emplace_back(x);
    }

    vector<int> reversArr(vector<int> &nums){
        vector<int> ans;
        solve(nums, ans);
        return ans;
    }  
};

int main () {
    
    return 0;
}