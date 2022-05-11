#include<iostream>
#include<algorithm>
using namespace std;

#define f(i,n,m)  for(int i=n;i<m;i++)

// Time complexity n*w
int knapsack(int wt[],int val[],int n,int W)
{
    int t[n+1][W+1];
    //initialization
    
    f(i,0,n+1)
    {
        f(j,0,W+1)
        {
            if(i==0 || j==0)
            t[i][j] = 0;
        }
    }
   
   f(i,1,n+1)
   {
       f(j,1,W+1)
       {
           if(wt[i-1]<=j)
           {
               t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
           }
           else
           {
               t[i][j] = t[i-1][j];
           }
       }
   }
    
    return t[n][W];
}

int main()
{
    int n;
    cin>>n;
    int wt[n],val[n];
    f(i,0,n)
    {
        cin>>wt[i];
    }
    f(i,0,n)
    {
        cin>>val[i];
    }
    int cap;
    cin>>cap; 

    cout<<knapsack(wt,val,n,cap);
    return 0;
}