// Check if a given string is palindrome or not

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    bool solve(string &s, int i, int j) {
        if (i > j) return true;
        return s[i] == s[j] && solve(s, i+1, j-1);
    }

    bool isPalindrome(string s){
        return solve(s, 0, s.length()-1);
    }
};

int main () {
    
    return 0;
}