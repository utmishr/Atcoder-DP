#include <bits/stdc++.h>
using namespace std;

int h, w;
char a[1005][1005];
int dp[1005][1005];
int M = 1e9+7;


int rec(int i,int j)
{
    //pruning
    if(i<0 || j<0)
    {
        return 0;
    }

    //base case
    if(i==0 && j==0)
    {
        return 1;
    }

    //check cache
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    //compute
    int ans=0;
    if(a[i-1][j]!='#')
    {
        ans=rec(i-1,j);
    }
    if(a[i][j-1]!='#')
    {
        ans=(ans+rec(i,j-1))%M;
    }
    
    //save and return
    return dp[i][j]=ans;
}

int main()
{
    cin >> h >> w;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(h-1,w-1)<<endl;
}