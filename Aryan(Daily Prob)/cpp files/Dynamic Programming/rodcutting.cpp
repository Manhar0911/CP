#include<bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)
#define ll long long int
#define endl "\n"

int maxcostrod(int len[],int val[],int n,int l)
{
   int dp[n+1][l+1];
   f(i,0,n+1)
   {
       f(j,0,l+1)
       {
           if(i==0 || j==0)
           dp[i][j] = 0;
       }
   }

   f(i,1,n+1)
   {
       f(j,1,l+1)
       {
           if(len[i-1] <= j)
           dp[i][j] = max( val[i-1] + dp[i][j-len[i-1]], dp[i-1][j]);
           else
           dp[i][j] = dp[i-1][j];
       }
   }
   return dp[n][l];
}

int main()
{
    int n,l;
    cin>>n>>l;
    int len[n],val[n];
    f(i,0,n)
    {
        cin>>len[i]>>val[i];
    }
    cout<<maxcostrod(len,val,n,l);
    return 0;
}