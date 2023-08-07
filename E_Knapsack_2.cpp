// https://youtu.be/o8N6vwEHo7M  --- good link to understand this in recurssive manner
// basically what you are doing is that we sum up all weight's value and after that we are checking from max_value to 0
// that whether set of weights of this much value is present or not. 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, w, a[100009], b[100009];
// a store weigth and b store value
ll dp[109][100009];

ll rec(int value_left, int level)
{

    // pruning

    // base case
    if (level == n)
    {
        if (value_left == 0)
        {
            return 0;
        }
        else
        {
            return INT_MAX;
        }
        // means you can't reach that value, so, you should not include this set of weights
        // in-short, it is not valid answer so you provide it int_max and on comparing it with w
        // in function s, it will not consider them.
    }

    // cache check
    if (dp[level][value_left] != -1)
        return dp[level][value_left];

    // compute
    ll ans = rec(value_left, level + 1);
    if (b[level] <= value_left)
        ans = min(ans, a[level] + rec(value_left - b[level], level + 1));

    // save and return
    return dp[level][value_left] = ans;
}

int s(int max_value)
{
    for (int i = max_value; i >= 0; i--)
    {
        if (rec(i, 0) <= w)
            return i;
    }
    return 0;
}

int main()
{
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    int max_value = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        max_value += b[i];
    }
    cout << s(max_value) << endl;
}
