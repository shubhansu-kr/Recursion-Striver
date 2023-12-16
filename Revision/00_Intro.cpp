// Recursion Intro

#include <bits/stdc++.h>
using namespace std ;

void f(){
    // No terminating condition - Leads to segementation fault
    cout << "!" << endl;

    // Recursive call
    f();
}

int count = 0; 
void f1(){
    // Terminating condition: Prints '!' 3 times
    if (count == 3) return;

    cout << "!" << endl;
    ++count;

    // Recursive call
    f1();
}

int main () {
    
    // f();
    f1();
    return 0;
}