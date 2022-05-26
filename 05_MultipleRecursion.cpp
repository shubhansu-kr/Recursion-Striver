// Multiple recursion calls - FIbonacci sequence

#include <bits/stdc++.h>
using namespace std;

// Find the Nth Fibonacci number
int fibonacci(int N)
{
    if (N == 0)
    {
        return 0;
    }
    if (N == 1)
    {
        return 1;
    }
    return fibonacci(N - 1) + fibonacci(N - 2);
}

int main()
{
    int N;
    cout << "Enter N : ";
    cin >> N;

    cout << "Fibonacci " << N << " is " << fibonacci(N) << endl;
    return 0;
}