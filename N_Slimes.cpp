//Generallylly in l-r DP we come up with 2 types of question - 1st you are given rod and you have to divide
//it and 2nd you are given small simes and you have to make up
//And if problem is in second we convert it into 1st form using prefix array -- you assume that there is whole slime and
//you try to divide it part by part
#include <bits/stdc++.h>
using namespace std;

int n;
long long a[455];
long long dp[455][455];

long long cost(int l, int r)
{
    if (l == 0)
        return a[r];
    return a[r] - a[l - 1];
}

long long rec(int l, int r)
{
    //pruning


    //base case
    if (l == r)
        return 0;


    // cache check
    if (dp[l][r] != -1)
        return dp[l][r];


    //compute
    long long ans = LLONG_MAX;
    for (int i = l; i < r; i++)
    {
        ans = min(ans, rec(l, i) + rec(i + 1, r) + cost(l, r));
    }

    // save and return
    return dp[l][r] = ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
        {
            a[i] += a[i - 1];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1) << endl;
}
