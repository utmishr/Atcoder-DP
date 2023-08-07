#include<bits/stdc++.h>
using namespace std;

int n;
double p[3005];
double dp[3005][3005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    dp[0][0] = 1.0 - p[0];             //dp[0][0] = 1.0 - p[0];:This line initializes the probability that,  
                                       //after tossing the first coin, you have 0 heads (tails). 
    dp[0][1] = p[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] * (1.0 - p[i]);
        for (int j = 1; j <= i + 1; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1.0 - p[i]);
        }
    }

    double result = 0.0;
    // n / 2 + 1: This part calculates the minimum number of heads you need to have in order to have more heads 
    // than tails in a total of n coin tosses. For example, if you're tossing 7 coins (n = 7), 
    // you need at least 4 heads to have more heads than tails.
    for (int j = n / 2 + 1; j <= n; j++)
    {
        result += dp[n - 1][j];
    }

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}


// Recursive code giving notanumber because of near 0 calculations

// #include <bits/stdc++.h>
// using namespace std;

// int n;
// double p[3005];
// double dp[3005][3005];

// double rec(int level, int x)
// {
//     // Pruning

//     // Base check
//     if (level >= n)
//     {
//         if (x > n - x)
//         {
//             return 0; // Return 0 instead of 1
//         }
//         else
//         {
//             return 1; // Return 1 instead of 0
//         }
//     }

//     // Check cache
//     if (dp[level][x] != -1)
//     {
//         return dp[level][x];
//     }

//     // Compute
//     double ans = 0;
//     ans = p[level] * rec(level + 1, x + 1) + (1 - p[level]) * rec(level + 1, x);

//     // Save and return
//     return dp[level][x] = ans;
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> p[i];
//     }
//     memset(dp, -1, sizeof(dp));
//     cout << fixed << setprecision(10) << rec(0, 0); // Print probability with precision
// }
