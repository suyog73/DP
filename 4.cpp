// Leetcode Coin Change 2
// https://leetcode.com/problems/coin-change-2/

#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int dp[310][10010];

int func(int idx, int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;

    if (idx < 0)
        return 0;

    if (dp[idx][amount] != -1)
        return dp[idx][amount];

    int ways = 0;
    for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[idx])
        ways += func(idx - 1, amount - coin_amount, coins);

    return dp[idx][amount] = ways;
}

int change(int amount, vector<int> &coins)
{
    memset(dp, -1, sizeof(dp));
    int ans = func(coins.size() - 1, amount, coins);
    return ans;
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

    cout << change(amount, v) << endl;
    return 0;
}