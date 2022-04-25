/*
    Given  2d array a of N*N integers. Given Q queries and in each query given a, b, c and d. Print sum of square represented by (a, b) as top left point and (c, d) as bottom right point.

    Constraints
    1 <= N <= 10^3
    1 <= a[i][j] <= 10^9
    1 <= Q <= 10^5
    1 <= a, b, c, d <= N

*/

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
const int N = 1e3 + 10;
int arr[N][N];
int prefSum[N][N];

void simpleApproach()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int sum = 0;
        for (int i = a; i <= c; i++)
        {
            for (int j = b; j <= d; j++)
            {
                sum += arr[i][j];
            }
        }
        cout << sum << "\n";
    }
}

// Prefix Sum Approach
void code()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            prefSum[i][j] = prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1] + arr[i][j];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << prefSum[c][d] - prefSum[a - 1][d] - prefSum[c][b - 1] + arr[a - 1][b - 1] << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // test_cases
    // simpleApproach(); // O(N^2) + O(Q*N^2)
    code();
}