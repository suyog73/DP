// Leetcode Coin Change
// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int dp[10010];

int func(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 0;

    if (dp[amount] != -1)
        return dp[amount];
    int ans = INT_MAX;
    for (int coin : coins)
    {
        if (amount - coin >= 0)
            ans = min(ans + 0ll, func(amount - coin, coins) + 1ll);
    }
    return dp[amount] = ans;
}

int coinChange(vector<int> &coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    int ans = func(amount, coins);

    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int amount;
    cin >> amount;

    cout << coinChange(v, amount) << endl;
    return 0;
}