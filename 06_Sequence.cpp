// Print all the subsequnece

#include <bits/stdc++.h>
using namespace std;

// Time complexity : 2^N 
// Space complexity : N
void printSubSequence(vector<int> A,int index = 0, vector<int> v = {})
{
    if (index >= A.size()) {
        for(int a : v) {cout << a << " ";}
        cout << endl;
        return;
    }
    v.emplace_back(A[index]) ;
    printSubSequence(A, index+1, v);
    v.pop_back();
    printSubSequence(A, index+1, v) ;
}

int main()
{
    vector<int> v = {1,2,3,5,6,3,6,3,5,23,4,2,4};
    printSubSequence(v);
    return 0;
}