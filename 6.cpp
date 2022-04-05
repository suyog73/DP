// Knapsack-2 Atcoder
// https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[105][100005];
int wt[105], val[105];

int func(int idx, int value_left)
{
    if (value_left == 0)
        return 0;

    if (idx < 0)
        return 1e15;

    if (dp[idx][value_left] != -1)
        return dp[idx][value_left];

    // Don't choose
    int ans = func(idx - 1, value_left);

    if (value_left - val[idx] >= 0)
        ans = min(ans, func(idx - 1, value_left - val[idx]) + wt[idx]);

    return dp[idx][value_left] = ans;
}

signed main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    int maxVal = 1e5;

    for (int i = maxVal; i >= 0; i--)
        if (func(n - 1, i) <= w)
        {
            cout << i << "\n";
            break;
        }
    return 0;
}