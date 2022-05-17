// Suyog Patil
// https://leetcode.com/problems/word-break/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &w)
    {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (auto st : w)
            {
                if (dp[i])
                {
                    string s1 = s.substr(i, st.size());
                    string s2 = st;

                    if (s1.compare(s2) == 0)
                        dp[i + st.size()] = true;
                }
            }
        }
        return dp[n];
    }
};
