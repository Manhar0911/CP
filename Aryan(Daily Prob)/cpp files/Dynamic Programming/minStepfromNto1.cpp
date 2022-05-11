#include<bits/stdc++.h>
using namespace std;


class Solution{

	public:
	int minSteps(int n) 
	{ 
	    // Your code goes here
	    //initializing dp array
	    int dp[n+1]={0};
	    // base case
	    dp[1] = 0;
	    
	    for(int i=2;i<n+1;i++)
	    {
	       if(i%3==0 && i%2==0)
	       {
	           dp[i] =  min( dp[i/3], min(dp[i/2] , dp[i-1]) ) + 1;
	       }
	       else if(i%2==0)
	       {
	           dp[i] = min(dp[i/2],dp[i-1]) + 1;
	       }
	       else if(i%3==0)
	       {
	           dp[i] = min(dp[i/3],dp[i-1]) + 1;
	       }
	       else
	       {
	           dp[i] = dp[i-1] + 1;
	       }
	    }
	    return dp[n];
	} 
};

int main()
{
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.minSteps(n)<<endl;
    return 0;
}