// Suyog Patil

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test_cases \
    int T;         \
    cin >> T;      \
    while (T--)
#define vsort(v) sort(v.begin(), v.end())
const int MOD = 1e9 + 7;

int mod_add(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

int fact(int n, int mod)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = mod_mul(ans, i, mod);
    }
    return (ans % mod);
}

int n;
vector<int> pal;
int dp[502][40004];

int totalWays(int idx, int amount)
{
    if (amount == 0)
        return 1;

    if (idx < 0)
        return 0;

    int &ans = dp[idx][amount];
    if (ans != -1)
        return ans;

    int ways = 0;

    for (int i = 0; i <= amount; i += pal[idx])
        ways += totalWays(idx - 1, amount - i);

    ways %= MOD;
    return ans = ways;
}

void code()
{
    cin >> n;
    cout << totalWays(pal.size() - 1, n) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= 40000; i++)
    {
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t)
            pal.push_back(i);
    }

    test_cases
    code();
}