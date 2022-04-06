// Longest Common Subsequence (LeetCode)
// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int func(int i, int j, string &a, string &b)
{
    if (i < 0 or j < 0)
        return 0;

    int &dpAns = dp[i][j];

    if (dpAns != -1)
        return dpAns;

    // remove 1 last char from a
    int ans = func(i - 1, j, a, b);

    // remove 1 last char from b
    ans = max(ans, func(i, j - 1, a, b));

    // remove 1 last char from a and b
    ans = max(ans, func(i - 1, j - 1, a, b) + (a[i] == b[j]));

    return dpAns = ans;
}

int longestCommonSubsequence(string a, string b)
{
    memset(dp, -1, sizeof(dp));
    return func(a.size() - 1, b.size() - 1, a, b);
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << longestCommonSubsequence(a, b) << "\n";
    return 0;
}