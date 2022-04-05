// Knapsack 1 Atcoder
// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;
#define int long long

int wt[105], val[105];
int dp[105][100005];

int func(int idx, int wt_left)
{
    if (wt_left == 0)
        return 0;

    if (idx < 0)
        return 0;

    if (dp[idx][wt_left] != -1)
        return dp[idx][wt_left];
    // Don't choose item at idx
    int ans = func(idx - 1, wt_left);

    // Choose item at idx
    if (wt_left - wt[idx] >= 0)
        ans = max(ans, func(idx - 1, wt_left - wt[idx]) + val[idx]);

    return dp[idx][wt_left] = ans;
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
    cout << func(n - 1, w) << "\n";

    return 0;
}