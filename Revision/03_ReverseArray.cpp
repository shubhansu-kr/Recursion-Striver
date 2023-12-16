// Reverse an array using recursion

#include <bits/stdc++.h>
using namespace std ;

class Solution2{
    // Smart Parameters.
public: 
    void solve(vector<int> &nums, int i, int j) {
        if (i >= j) return;
        swap(nums[i], nums[j]);
        solve(nums, i+1, j-1);
    }

    vector<int> reversArr(vector<int> &nums){
        solve(nums, 0, nums.size()-1);
        return nums;
    }
};

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