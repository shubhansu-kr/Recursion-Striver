// Recursion Intro

#include <bits/stdc++.h>
using namespace std;

void f()
{
    // NO base condition : Leads to segmentation fault.
    cout << "!" << endl;
    f();
}

int num = 0;
void f1()
{
    // Base condition to break out of recursion 
    if (num == 3)
    {
        return;
    }
    cout << num << " " << endl;
    ++num;
    f1();
}

int main()
{

    // f();
    f1();
    return 0;
}