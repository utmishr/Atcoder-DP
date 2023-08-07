//NOT OPTIMIZED --- WATCH https://youtu.be/J-W7EX36UTY (for optimized itterative code)
#include<bits/stdc++.h>
using namespace std;

int n, k;
int dp[105][100100];
int a[105];
const int MOD = 1e9 + 7;

int rec(int level, int left)
{
    // base case
    if (left == 0)
    {
        return 1;
    }
    
    if (level == n || left < 0)
    {
        return 0;
    }

    // check cache
    if (dp[level][left] != -1)
    {
        return dp[level][left];
    }

    // compute
    int ans = 0;
    
    for (int x = 0; x <= a[level]; x++)
    {
        ans = (ans + rec(level + 1, left - x)) % MOD;
    }

    // save and return
    return dp[level][left] = ans;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, k) << endl;
    return 0;
}