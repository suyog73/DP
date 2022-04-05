// Suyog Patil
// Frog 1
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test_cases \
    int T;         \
    cin >> T;      \
    while (T--)
#define vsort(v) sort(v.begin(), v.end())
int const N = 1e5 + 10;
int h[N];
int dp[N];
int k;

int func(int x)
{
    if (x == 0)
        return 0;

    int cost = INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    for (int i = 1; i <= k; i++)
        if (x >= i)
            cost = min(cost, func(x - i) + abs(h[x] - h[x - i]));

    return dp[x] = cost;
}

void code()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << func(n - 1) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // test_cases
    code();
}