// Rod Cutting GFG
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1005];
    int func(int len, vector<int> &prices)
    {
        if (len == 0)
            return 0;

        int &dpAns = dp[len];
        if (dpAns != -1)
            return dpAns;

        int ans = 0;
        for (int len_to_cut = 1; len_to_cut <= prices.size(); len_to_cut++)
        {
            if (len - len_to_cut >= 0)
                ans = max(ans, func(len - len_to_cut, prices) + prices[len_to_cut - 1]);
        }
        return dpAns = ans;
    }

    int cutRod(int price[], int n)
    {
        memset(dp, -1, sizeof(dp));
        vector<int> prices(price, price + n);
        int ans = func(n, prices);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ab;

        cout << ab.cutRod(a, n) << "\n";
    }

    return 0;
}