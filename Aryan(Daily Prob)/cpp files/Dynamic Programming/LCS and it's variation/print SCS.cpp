#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define f(i,n,m) for(ll i=n;i<m;i++)

string SCS(string X, string Y, int n, int m)
{
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(j==0)
                dp[i][j] = i;
                else if(i==0)
                dp[i][j] = j;
                else if(X[i-1]==Y[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]); 
                }
            }
        }
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
       
       int i = n;
       int j = m;
       string ans = "";
       while(i>0 || j>0)
       {
           if(X[i-1]==Y[j-1])
           {
               ans = ans + X[i-1];
               i--;
               j--;
           }
           else
           {
               if(dp[i-1][j]>dp[i][j-1])
               {
                   ans = ans + Y[j-1];
                   j--;
               }
               else
               {
                   ans = ans + X[i-1];
                   i--;
               }
           }
       }
       reverse(ans.begin(),ans.end());
       return ans;
}

int main()
{   
    string X, Y;
	cin >> X >> Y;
	
	cout <<SCS(X, Y, X.size(), Y.size())<< endl;
	return 0;
}


