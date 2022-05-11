// solution 1 (bottom - up)

#include<bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)
string static t[1001][1001];

string LCS(string x,string y,int n,int m)
{
    if(n==0 || m==0)
    return "";

    if(t[n][m] != "")
    return t[n][m];

    //choice diagram

    if(x[n-1] == y[m-1])
    return t[n][m] =  x[n-1] + LCS(x,y,n-1,m-1);
    else
    {
        int opt1 = LCS(x,y,n-1,m).length();
        int opt2 = LCS(x,y,n,m-1).length();
        if(opt1>opt2)
        {
           return t[n][m] = LCS(x,y,n-1,m); 
        }
        else
        {
           return t[n][m] = LCS(x,y,n,m-1);  
        }
    }
}

int main()
{
    string x,y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();

    f(i,0,n+1)
    {
        f(j,0,m+1)
        {
            t[i][j] = "";
        }
    }

    string str = LCS(x,y,n,m);
    reverse(str.begin(), str.end());
    cout<<str<<endl;
    return 0;
}
/*
// solution 2 top - down

#include<bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)

string LCS(string x,string y,int n,int m)
{
    string dp[n+1][m+1];
    //initilizatisation
    f(i,0,n+1)
    {
        f(j,0,m+1)
        {
            if(i==0 || j==0)
            dp[i][j] = "";
        }
    }
    
    f(i,1,n+1)
    {
        f(j,1,m+1)
        {
            if(x[i-1]==y[i-1])
            dp[i][j] = x[i-1] + dp[i-1][j-1];
            else
            {
                int opt1 = dp[i-1][j].length();
                int opt2 = dp[i][j-1].length();
                if(opt1>opt2)
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    string str = dp[n][m];
    reverse(str.begin(), str.end());
    return str;
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

// solution 3 (least space complexity) i.e. BEST APPROCH
#include<bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)

string LCS(string x,string y,int n,int m)
{
    int dp[n+1][m+1];
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
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
     f(i,0,n+1)
    {
        f(j,0,m+1)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int i=n,j=m;
    string str="";
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            str = str + x[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            else
            j--;
        }
    }
    return str;
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
*/