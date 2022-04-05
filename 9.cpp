// Subset Sum Problem!
// https://www.interviewbit.com/problems/subset-sum-problem/

#include <bits/stdc++.h>
using namespace std;

int dp[105][100005];

int myFunc(int n, int sum, vector<int> &v)
{
    if (sum == 0)
        return 1;

    if (n < 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    // Don't consider current element
    bool isPossible = myFunc(n - 1, sum, v);

    // Consider it
    if (sum - v[n] >= 0)
        isPossible |= myFunc(n - 1, sum - v[n], v);

    return dp[n][sum] = isPossible;
}

bool solve(vector<int> &v, int sum)
{
    memset(dp, -1, sizeof(dp));
    return myFunc(v.size() - 1, sum, v);
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

    int sum;
    cin >> sum;

    cout << solve(v, sum) << "\n";
    return 0;
}