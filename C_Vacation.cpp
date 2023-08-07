#include <bits/stdc++.h>
using namespace std;

// Here at level=0, all three are possible but after that only two are possible

int n;
int cost[3][100100];
int dp[100100][3];

int rec(int level, int last)
{
    // Base case: Reached the last level
    if (level == n)
    {
        return cost[last][level];
    }

    // Check cache
    if (dp[level][last] != -1)
    {
        return dp[level][last];
    }

    //compute
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            ans = max(ans, rec(level + 1, i) + cost[i][level]);
        }
    }

    // Save and return
    return dp[level][last] = ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[j][i];
        }
    }
    memset(dp, -1, sizeof(dp));
    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        result = max(result, rec(1, i)+cost[i][0]);
    }
    cout << result << endl;
}
