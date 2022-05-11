#include<bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)

int maxSubarraySum(int n,int arr[])
{
    int dp[n][n]={0};
    int maxi = INT_MIN;
    f(i,0,n)
    {
        f(j,0,n)
        {
            if(i==j)
            {
                dp[i][j] = arr[i];
                maxi = max(maxi,arr[i]);
            }
        }
    }
     int j;
    for(int i=0; i<n && j<n ; i++)
    {
        while(j<n)
        {
            if(i+1 == j)
            {
                dp[i][j] = dp[i+1][j] + dp [i][j-1];
                maxi = max(maxi,dp[i][j]);
            }
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    f(i,0,n)
    {
        cin>>a[i];
    }
    cout<<maxSubarraySum(n,a);
    return 0;
}