#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int N, A[21][21], dp[1 << 21];

int rec(int mask, int cnt)
{

    //pruning 


    // Base case
    if (cnt == N)
    {
        return 1;
    }

    // Cache check
    if (dp[mask] != -1)
    {
        return dp[mask];
    }

    //compute
    int ways = 0;
    for (int j = 0; j < N; j++)
    {
        // Check if Woman j is not paired and is compatible with the current count
        if (!(mask & (1 << j)) && A[cnt][j] == 1)
        {
            ways += rec(mask | (1 << j), cnt + 1);
            if (ways >= mod)
            {
                ways -= mod;
            }
        }
    }

    // Save and return
    return dp[mask] = ways;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
    return 0;
}
