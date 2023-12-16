// Fibonacci    

#include <bits/stdc++.h>
using namespace std ;

class Solution{
public: 
    int fibonacci(int n){
        if (n < 2) return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }
};

int main () {
    
    return 0;
}