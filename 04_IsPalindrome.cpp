// Check if a string is palindrome 

#include <bits/stdc++.h>
using namespace std ;

// two pointer approach
bool isPalindrome(string s, int r, int l=0) {
    if (l >= r) {
        return true;
    }
    if (s[l] == s[r]) {
        return isPalindrome(s, r-1, l+1) ;
    }
    else {
        return false ;
    }
}

// Using one pointer 
bool isPalindromeA(string s, int i = 0) {
    if (i >= s.length()/2) {
        return true;
    }
    if (s[i] == s[s.length()-i-1]) {
        return isPalindromeA(s, i+1);
    }
    else {
        return false;
    }
}

int main () {
    vector<string> v = {"1221", "3434", "45454", "986875"} ;

    for(auto a : v) {
        cout << isPalindrome(a, a.size()-1) << " " ;
    }
    
    cout << endl;

    for(auto a : v) {
        cout << isPalindromeA(a) << " " ;
    }

    return 0;
}