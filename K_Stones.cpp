#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[105];
int dp[100100];

bool rec(int left)
{
    //pruning
    if(left<0)                  //because one such case is possible in which first person make second to go in this condition
    {
        return 1;
    }

    //base case                 //because one such case is possible in which second person make first to go in this condition
    if(left == 0)
    return 0;

    //check cache
    if(dp[left]!=-1)
    {
        return dp[left];
    }

    //compute
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(rec(left-a[i])==0)
        {
            ans=1;
            break;
        }
    }

    //save and return
    return dp[left]=ans;
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    if(rec(k))
    {
        cout<<"First";
    }
    else
    {
        cout<<"Second";
    }
}