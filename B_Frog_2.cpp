#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005];
int dp[100005];

int rec(int level)
{
    // pruning and base case
    if (level >= n - 1) // once you come to level n-1 you can't go ahead and it return 0
    {                   // remember the cost to come at n-1 will already calclated by h1-hj and rec(n-1) should return 0
        return 0;
    }

    // check cache
    if (dp[level] != -1)
    {
        return dp[level];
    }

    // compute
    int ans = 1e9;
    for (int i = 1; i <= k; i++)
    {
        if (level + i < n)
        {
            ans = min(ans, rec(level + i) + abs(a[level + i] - a[level]));
        }
    }

    // save and return
    return dp[level] = ans;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0);
}