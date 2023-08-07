#include <bits/stdc++.h>
using namespace std;

string s, t;
int dp[3005][3005];

int rec(int i, int j)
{
    // pruning

    // base case
    if (i == s.size() || j == t.size())
    {
        return 0;
    }

    // cache check
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // compute
    int ans = 0;
    ans = max(ans, rec(i + 1, j));
    ans = max(ans, rec(i, j + 1));
    if (s[i] == t[j])
    {
        ans = max(ans, rec(i + 1, j + 1) + 1);
    }

    // save and return
    return dp[i][j] = ans;
}

string sol;
void print(int i, int j)
{
    // There are three possible cases for the value of rec(i, j) compared to its neighboring values (rec(i + 1, j) and 
    // rec(i, j + 1)):

    // If rec(i, j) == rec(i + 1, j), it means that the length of the LCS remains the same if we skip the
    // current character in string s. In this case, the function makes a recursive call to print(i + 1, j),
    // effectively moving to the next character in string s while keeping the same position in string t.

    // If rec(i, j) == rec(i, j + 1), it means that the length of the LCS remains the same if we skip the
    // current character in string t. In this case, the function makes a recursive call to print(i, j + 1),
    // effectively moving to the next character in string t while keeping the same position in string s.

    // If neither of the above cases is true, it means that the current characters in both strings (s[i] and t[j])
    // are part of the LCS. The function appends the current character from s to the sol string (which seems to
    // store the reconstructed LCS). Then, it makes a recursive call to print(i + 1, j + 1) to continue searching for
    // the remaining characters of the LCS.
    if (i == s.size() || j == t.size())
    {
        return;
    }
    if (rec(i, j) == rec(i + 1, j))
    {
        print(i + 1, j);
    }
    else if (rec(i, j) == rec(i, j + 1))
    {
        print(i, j + 1);
    }
    else                        // rec(i,j)==rec(i+1,j + 1)+1
    {
        sol += s[i];
        print(i + 1, j + 1);
    }
    // These all take O(1) as all rec() are already computed
}

int main()
{
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    print(0, 0);
    cout << sol << endl;
}