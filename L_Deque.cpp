// Very good question where both min and max concept is used.
#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[3005];
long long dp[3005][3005];

long long rec(long long i, long long j)
{
    // base case
    if (i > j)
    {
        return 0;
    }

    // cache check
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // compute
    long long take_left = a[i] + min(rec(i + 2, j), rec(i + 1, j - 1));
    long long take_right = a[j] + min(rec(i + 1, j - 1), rec(i, j - 2));
    long long ans = max(take_left, take_right);

    // save and return
    return dp[i][j] = ans;
}

int main()
{
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    memset(dp, -1, sizeof(dp));
    long long taro_score = rec(0, n - 1);
    long long jiro_score = sum - taro_score;
    cout << taro_score - jiro_score << endl;
    return 0;
}
