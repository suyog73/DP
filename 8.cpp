// Partition Equal Subset Sum (LeetCode)
// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

int dp[205][20005];

bool func(int idx, int sum, vector<int> &v)
{
    if (sum == 0)
        return 1;

    if (idx < 0)
        return 0;

    int &ans = dp[idx][sum];

    if (ans != -1)
        return ans;

    // idx not consider
    bool isPossible = func(idx - 1, sum, v);

    // consider idx
    if (sum - v[idx] >= 0)
        isPossible |= func(idx - 1, sum - v[idx], v);

    return ans = isPossible;
}

bool canPartition(vector<int> &v)
{
    memset(dp, -1, sizeof(dp));
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];

    if (sum % 2)
        return 0;

    sum /= 2;

    return func(v.size() - 1, sum, v);
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

    cout << (canPartition(v) ? "true" : "false") << "\n";
    return 0;
}