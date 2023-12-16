// Parameterised Recursion || Functional way

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // Sum of First N numbers 
    // Parameterised Way - We carry a parameter to hold the result
public: 
    void solve(int &sum, int n){
        if (n < 1) return;
        sum += n;
        solve(sum, n-1);
    }
    
    int naturalSum(int n){
        int sum = 0;
        solve(sum, n);
        return sum;
    }
};

class Solution {
    // Sum of First N numbers 
    // Functional Way - We do not carry a parameter to hold the result
public: 
    int naturalSum(int n){
        if (n < 1) return 0;
        return n + naturalSum(n-1);    
    }
};

int main () {
    
    return 0;
}