// Count the number of subsequence with sum k

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(2^N);
// Space Complexity : O(N);

// Whenever Question asks you to count : Follow 0 or 1;
int sumCount(vector<int> A, int i = 0, int sum = 0)
{
    if (i >= A.size())
    {
        return sum == 6;
    }
    sum += A[i];
    int l = sumCount(A, i + 1, sum);
    sum -= A[i];
    int r = sumCount(A, i + 1, sum);
    return l + r;
}

int main()
{
    vector<int> vec = {3, 4, 2, 3, -1, 1, 0};
    cout << sumCount(vec);
    return 0;
}