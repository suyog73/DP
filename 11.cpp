// Suyog Patil
// https://codeforces.com/problemset/problem/1660/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define test_cases \
    int T;         \
    cin >> T;      \
    while (T--)
#define vsort(v) sort(v.begin(), v.end())

string s;
int dp[200005];

int func(int i)
{
    if (i >= s.size())
        return 0;

    int &dpAns = dp[i];

    if (dpAns != -1)
        return dpAns;

    if (i == s.size() - 1)
        return 1;

    if (i < s.size() - 1 and s[i] == s[i + 1])
        return func(i + 2);
    else
    {
        int j;
        for (j = i + 1; j < s.size(); j++)
        {
            if (s[j] == s[i])
                break;
        }

        if (j == s.size())
            return 1 + func(i + 1);

        else
        {
            // cout << j << " " << i << "\n";
            int a = j - i - 1 + func(j + 1);
            int b = 1 + func(i + 1);

            return dpAns = min(a, b);
        }
    }
}

void code()
{
    memset(dp, -1, sizeof(dp));
    cin >> s;

    cout << func(0) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test_cases
    code();
}