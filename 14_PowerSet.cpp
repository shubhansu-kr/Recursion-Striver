// Power set

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> powerSet(string s)
    {
        vector<string> res;
        for (int i = 0; i <= (1 << s.size()) - 1; ++i)
        {
            string sub = "";
            for (int j = 0; j < s.size(); ++j)
            {
                if (i & (1 << j))
                {
                    sub += s[j];
                }
            }
            res.emplace_back(sub);
            cout << sub << endl;
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution obj1;
    obj1.powerSet("abc");
    return 0;
}