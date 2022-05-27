// SubSequence with sum K

#include <bits/stdc++.h>
using namespace std;

// Code funcitonal for Every Integer. Z
void subSequenceSum(vector<int> A, vector<int> &v, int i = 0, int sum = 0)
{
    if (i >= A.size())
    {
        if (sum == 6)
        {
            for (int a : v)
            {
                cout << a << " ";
            }
            cout << endl;
        }
        return;
    }
    v.emplace_back(A[i]);
    sum += A[i];
    subSequenceSum(A, v, i + 1, sum);
    v.pop_back();
    sum -= A[i];
    subSequenceSum(A, v, i + 1, sum);
}

// Code fucntional for positive intergers only. +Z ;
void subSequenceSumP(vector<int> A, vector<int> &v, int i = 0, int sum = 0)
{
    if (i >= A.size() || sum == 6)
    {
        if (sum == 6)
        {
            for (int a : v)
            {
                cout << a << " ";
            }
            cout << endl;
        }
        return;
    }
    v.emplace_back(A[i]);
    sum += A[i];
    subSequenceSumP(A, v, i + 1, sum);
    v.pop_back();
    sum -= A[i];
    subSequenceSumP(A, v, i + 1, sum);
}

int c = 0;
void sumCount(vector<int> A, int i = 0, int sum = 0)
{
    if (i >= A.size())
    {
        if (sum == 6)
        {
            ++c;
        }
        return;
    }
    // Take
    sum += A[i];
    sumCount(A, i + 1, sum);
    // Dont Take
    sum -= A[i];
    sumCount(A, i + 1, sum);
}

int main()
{
    vector<int> vec = {3, 4, 2, 3, -1, 1, 0};
    vector<int> v;
    subSequenceSumP(vec, v);
    cout << "ALL " << endl;
    subSequenceSum(vec, v);
    sumCount(vec);
    cout << "count " << c << endl;
    return 0;
}