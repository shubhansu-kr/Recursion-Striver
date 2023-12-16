// Recursion Practice: Tail - NonTail Recursion

#include <bits/stdc++.h>
using namespace std ;

// Print names five times
int count = 0;
void f(string &s){
    if (count == 5) break;

    print(s);
    ++count;
    f(s);
}

// Print Linearly from 1 to N
int a = 1;
void f(int &n) {
    if (a > n) return;

    print(a);
    ++a;
    f(n);
}

// Print from N to 1;
int b = 0;
void f(){
    if(b == 0) return;

    print(b);
    b--;
    f();
}

// Print from N to 1 using backtracking
int c = 1;
void f(int &n, bool t){
    if (c > N) return;

    ++c;
    f(n, true);
    print(c);
}

// Print from 1 to N using backtracing
int d = 0;
void f(bool t) {
    if (d == 0) return;

    d--;
    f(true);
    print(d);
}

int main () {

    // name 5 times
    string name = "Shubh";
    f(name);

    // 1 To N
    int n = 5;
    f(n);


    // N to 1
    b = n;
    f();

    // BackTrack: N to 1
    f(n, true);

    // Back track: 1 to N
    d = n;
    f(true);

    return 0;
}