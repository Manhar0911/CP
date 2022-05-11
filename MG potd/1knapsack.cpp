#include<bits/stdc++.h>
using namespace std;

int knapsack(int n,int wt[],int val[],int W,int dp[1001][1001])
{
    if(n==0 || W==0)
    return 0;
   
    if(dp[n][W]!=-1)
    return dp[n][W];

    if(wt[n-1]<=W)
    return dp[n][W] = max(val[n-1] + knapsack(n-1,wt,val,W-wt[n-1],dp),knapsack(n-1,wt,val,W,dp));
    else
    return dp[n][W] = knapsack(n-1,wt,val,W,dp);
}


int main()
{
   // int n;
   // cin>>n;
    int wt[]={1,4,6,3};
    int val[] ={4,2,2,7};
    int W=7;
    int dp[1001][1001];
    memset(dp,sizeof(dp),-1);
    cout<<knapsack(4,wt,val,W,dp);
    return 0;
}