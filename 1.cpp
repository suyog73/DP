// Fibbonacci series by DP
// 0 1 1 2 3 5 ...
// Top down approach
// Time Complexity o(2^n) ==> o(n) using dp

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int dp[N];
int counta = 0;

int fib(int n)
{
    counta++;
    if (n == 0 or n == 1)
        return n;

    // Memoise
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n = fib(31);
    cout << n << endl;
    cout << counta << endl;
    return 0;
}