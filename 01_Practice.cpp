// Practice problems

#include <bits/stdc++.h>
using namespace std;

// Print name 5 times

// Note : We can always use global variables to execute a base case
// but using a parameter in function is always recommended as the
// memory used by the parameter var is deleted once the function
// is executed sucessfully.

// Using global var
// int c1 = 0;
// void printName()
// {
//     if (c1 == 5)
//         return;
//     cout << "Shubh ";
//     ++c1;
//     printName();
// }

// Using Parameters
void printName(int N, int i = 1)
{
    if (i > N)
        return;
    cout << "Shubh ";
    printName(N, i + 1);
}

// Print linearly from 1 to N

// Using Global Var
// int c2 = 1;
// void printNum(int N)
// {
//     if (c2 > N)
//         return;
//     cout << c2 << " ";
//     ++c2;
//     printNum(N);
// }

// Using Parameters
void printNum(int N, int i = 1)
{
    if (i > N)
        return;
    cout << i << " ";
    printNum(N, i + 1);
}

// Print linearly from N to 1
void printNumRev(int N)
{
    if (N < 1)
        return;
    cout << N << " ";
    printNumRev(--N);
}

// Print Lineraly from 1 to N using BackTracking
void printNumB(int N)
{
    if (N < 1)
        return;
    printNumB(N - 1);
    cout << N << " ";
}

// Print Linearly from N to 1 using Backtracking

// Using Global var
// int c3 = 1;
// void printNumRevB(int N)
// {
//     if (c3 > N)
//         return;
//     ++c3;
//     printNumRevB(N);
//     --c3;
//     cout << c3 << " ";
// }

// Using parameters
void printNumRevB(int N, int i = 1)
{
    if (i > N)
        return;
    printNumRevB(N, i + 1);
    cout << i << " ";
}

int main()
{
    int N;
    cout << "Enter N : ";
    cin >> N;

    // Print name 5 times
    printName(N);

    // Print Linearly from 1 to N
    cout << endl;
    printNum(N);

    // Print Linearly from N to 1
    cout << endl;
    printNumRev(N);

    // Print Linearly from 1 to N using BackTracking
    cout << endl;
    printNumB(N);

    // Print Linearly from N to 1 using BackTracking
    cout << endl;
    printNumRevB(N);

    // Note : Time Complexity O(N) , Space Complexity O(N).
    
    return 0;
}