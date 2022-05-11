#include<bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)

int LCS(string x,string y,int n,int m)
{
    int dp[n+1][m+1];
    int maxval=0;
    //initilizatisation
    f(i,0,n+1)
    {
        f(j,0,m+1)
        {
            if(i==0 || j==0)
            dp[i][j] = 0;
        }
    }
    
    f(i,1,n+1)
    {
        f(j,1,m+1)
        {
            if(x[i-1]==y[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = 0;
        }
    }
    f(i,0,n+1)
    {
        f(j,0,m+1)
        {
            maxval = max(maxval,dp[i][j]);
        }
    }
    return maxval;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
       string x,y;
       cin>>x>>y;
       int n = x.length();
       int m = y.length();
       cout<<LCS(x,y,n,m)<<endl;
    }
       return 0;
}