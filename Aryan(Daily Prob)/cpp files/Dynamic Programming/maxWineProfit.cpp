#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vll vector<long long int>
#define vld vector<long double>
#define pll pair<long long int,long long int>
#define f(i,n,m) for(int i=n;i<m;i++)
#define ll long long int
#define ld long double
#define pi 3.141592653589793238
#define Endl endl
#define endl "\n"

int maxWineProfit(int n, int arr[], int y, int i, int j, vector<vector<int>>dp)
{
    if(j<i)
    return 0;
    
    if(dp[i][j]!=0)
    return dp[i][j];
    
    int first = arr[i]*y;
    int last = arr[j]*y;
    
    int opt1 = first + maxWineProfit(n,arr,y+1,i+1,j,dp);
    int opt2 = last + maxWineProfit(n,arr,y+1,i,j-1,dp);
    
    return dp[i][j] = max(opt1,opt2);
    
}

int main()
{
    FAST;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        f(i,0,n)
        {
            cin>>arr[i];
        }
        vector<vector<int>>dp(n, vector<int>(n,0));
        f(i,0,n)
        {
            f(j,0,n)
            {
                dp[i][j] = 0;
            }
        }
        cout<<maxWineProfit(n,arr,1,0,n-1,dp);
    }
    return 0;
}
