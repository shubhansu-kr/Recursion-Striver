// Parameterised and Functional Recursion

#include <bits/stdc++.h>
using namespace std;

// Sum of first N number

// Using global parameter
// int sum = 0;
// void sumNum(int N, int i = 1)
// {
//     if (i > N)
//         return;
//     sum += i;
//     sumNum(N, i + 1);
// }

int sumNum(int N, int sum = 0, int i = 1)
{
    if (i > N)
        return sum;
    return sumNum(N, sum += i, i + 1);
}

// Functionnal way
int sumNumF(int N)
{
    if (N == 0)
        return 0;
    return sumNumF(N - 1) + N;
}

// Find the factorial of N 
int factorialN(int N) {
    if (N == 0) return 1 ;
    return N * factorialN(N-1) ;
}

// IF you wish to execute some code only once during whole recursion
// condition, put the code in the base condition block.
// Since the base condition is executed only once in all of recursion.

// Parameterised way
void sumNumP(int N, int sum = 0)
{
    if (N < 1)
    {
        cout << "Sum is : " << sum << endl;
        return;
    }
    sumNumP(N - 1, sum += N);
}

int main()
{
    int N;
    cout << "Enter N : ";
    cin >> N;

    // Sum of first N number;
    // cout << sum << endl;
    cout << sumNum(N) << endl;
    cout << sumNumF(N) << endl;
    cout << factorialN(N) << endl;
    sumNumP(N);
    return 0;
}