// this is O(n+m) only because we take average because each edge can be in one of the node
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> g[100100];
int dp[100100];

int rec(int x)
{
    //pruning

    //base case

    //check cache
    if(dp[x]!=-1)
    {
        return dp[x];
    }

    //compute
    int ans=0;
    for(auto v:g[x])
    {
        ans=max(ans,1+rec(v));
    }

    //save ans return
    return dp[x]=ans;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    memset(dp,-1,sizeof(dp));
    int final_ans=0;
    for(int i=1;i<=n;i++)
    {
        final_ans=max(final_ans,rec(i));
    }
    cout<<final_ans<<endl;
}