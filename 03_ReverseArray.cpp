// Reverse Array

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Store the element while progressing and reassign while returning.
// However, using global var ain't recommended.

int i = 0;
void reverseArr(vector<int> &A)
{
    if (i == A.size())
    {
        i = 0;
        return;
    }
    int temp = A[i];
    ++i;
    reverseArr(A);
    A[i] = temp;
    ++i;
}

// swap using two pointer
void reverseArr(vector<int> &A, int r, int l = 0)
{
    if (l >= r)
    {
        return;
    }
    swap(A[l], A[r]);
    reverseArr(A, r - 1, l + 1);
}

// Swap using one pointer 
void reverse(vector<int> &A, int i=0) {
    if (i >= A.size()/2) {
        return ;
    }
    swap(A[i], A[A.size()-i-1]);
    reverse(A, i+1);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int a : v)
    {
        cout << a << " ";
    }
    cout << endl;

    // Reverse the array
    reverseArr(v);
    for (int a : v)
    {
        cout << a << " ";
    }
    cout << endl;

    reverseArr(v, v.size() - 1);

    for (int a : v)
    {
        cout << a << " ";
    }
    cout << endl;

    reverse(v);
    for (int a : v)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}