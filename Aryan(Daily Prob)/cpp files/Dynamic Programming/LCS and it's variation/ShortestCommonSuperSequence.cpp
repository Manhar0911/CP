// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
#define f(i,n,m) for(int i=n;i<m;i++)
int static dp[1001][1001];

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        memset(dp,-1,sizeof(dp));
        return SCS(X,Y,m,n,0,0);
    }
    int SCS(string x,string y,int n,int m,int i,int j)
    {
         if(i==n || j==m)
         return n+m;
    
       if(dp[i][j]!=-1)
       {
          return dp[i][j];
       }

        if(x[i] == y[j])
        {
           return dp[i][j] = (SCS(x,y,n,m,i+1,j+1) - 1); 
        }
        else
        {
           int opt1 = SCS(x,y,n,m,i+1,j);
           int opt2 = SCS(x,y,n,m,i,j+1);
           //cout<<opt1<<opt2<<" ";
           return dp[i][j] = min(opt1,opt2);
        }
        
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends