// Precomputation Technique (Prefix Sum)

/*

Given array a of N integers. Given Q queries and in each query given L and R print sum of array elements from index L to R(L and R included).

Constraints
1 <= N <= 10^5
1 <= a[i] <= 10^9
1 <= Q <= 10^5
1 <= L, R <= N


A[6] = {3, 6,  2,  8,  9,  2}
P[6] = {3, 9, 11, 19, 28, 30} ==> Prefix Sum Array

Here P[i] denotes the sum of elements from 1 to i

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

const int N = 1e5 + 10;
int p[N];

void simpleApproach()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int sum = 0;
        for (int i = l; i <= r; i++)
            sum += v[i];

        cout << sum << "\n";
    }
}

// Prefix Sum solution
void code()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        p[i] = p[i - 1] + v[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << p[r] - p[l - 1] << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // test_cases
    // simpleApproach(); // O(N) + O(Q * N)
    code(); // O(N) + O(Q)
}