#include<bits/stdc++.h>
using namespace std;

long long n;
long long dp[105][100100];
long long w;
long long a[105][2];

long long rec(long long level, long long left)
{
    //pruning

    //base case
    if(level==n)
    {
        return 0;
    }

    //check cache
    if(dp[level][left]!=-1)
    {
        return dp[level][left];
    }

    //compute
    long long ans=-1;
    ans=max(ans,rec(level+1,left));
    if(left-a[level][0]>=0)
    {
        ans=max(ans,rec(level+1,left-a[level][0])+a[level][1]);
    } 

    //save and return
    return dp[level][left]=ans;

}

int main()
{
    cin>>n>>w;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin>>a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(0,w)<<endl;
}
