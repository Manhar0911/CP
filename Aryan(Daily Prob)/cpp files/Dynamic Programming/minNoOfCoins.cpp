

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
        int dp[V+1]={0};
        
        for(int i=1;i<=V;i++)
        {
            dp[i] = INT_MAX;
            for(int j=0;j<M;j++)
            {
                if (coins[j] <= i)
          {
              int sub_res = dp[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                  dp[i] = sub_res + 1;
          }    
            }
        }
        if(dp[V]==INT_MAX)
        return -1;
        
        return dp[V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends

//method 2
/*

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int m, int sum) 
	{ 
	    int dp[m+1][sum+1];
	    
	    //initilisation
	    for(int i=0;i<m+1;i++)
	    {
	        for(int j=0;j<sum+1;j++)
	        {
	            if(i==0)
	            dp[i][j] = INT_MAX-1;
	            if(j==0)
	            dp[i][j] = 0;
	        }
	    }
	    
	    for(int i=1;i<m+1;i++)
	    {
	        for(int j=1;j<sum+1;j++)
	        {
	           if(coins[i-1]<=j)
	           dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
	           else
	           dp[i][j] = dp[i-1][j];
	        }
	    }
	    if(dp[m][sum]==INT_MAX-1)
	    return -1;
	    else
	    return dp[m][sum];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends

*/