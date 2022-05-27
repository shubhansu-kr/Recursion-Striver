// End the recursion as soon as you hit the first base condition in
// multiple recursion call funciton.

#include <bits/stdc++.h>
using namespace std;

bool isSumK(vector<int> A, int i = 0, int sum = 0)
{
    cout << " * " ;
    if (i >= A.size() || sum == 6)
    {
        return sum == 6;
    }
    sum += A[i];
    if (isSumK(A, i + 1, sum)) {
        return true;
    }
    sum -= A[i];
    if (isSumK(A, i + 1, sum)) {
        return true;
    }
    return false ;
}

int main()
{
    vector<int> vec = {3, 6, 3};
    cout << isSumK(vec);
    return 0;
}