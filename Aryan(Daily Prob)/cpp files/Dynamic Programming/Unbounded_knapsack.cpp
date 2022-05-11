#include<bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)
#define ll long long int
#define endl "\n"

int unbounded_knapsack(int wt[],int val[],int n,int w)
{
   int dp[n+1][w+1];
   f(i,0,n+1)
   {
       f(j,0,w+1)
       {
           if(i==0 || j==0)
           dp[i][j] = 0;
       }
   }

   f(i,1,n+1)
   {
       f(j,1,w+1)
       {
           if(wt[i-1] <= j)
           dp[i][j] = max( val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
           else
           dp[i][j] = dp[i-1][j];
       }
   }
   return dp[n][w];
}

int main()
{
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    f(i,0,n)
    {
        cin>>wt[i]>>val[i];
    }
    cout<<unbounded_knapsack(wt,val,n,w);
    return 0;
}