#include<iostream>
#include<algorithm>
using namespace std;

#define f(i,n,m)  for(int i=n;i<m;i++)

// Time complexity 2^n recursive solution
int knapsack(int wt[],int val[],int n,int W)
{
    //base condition
    if(n==0 || W==0)
    return 0;

    if(wt[n-1]<=W)
    {
        return max(val[n-1] + knapsack(wt,val,n-1,W-wt[n-1]) , knapsack(wt,val,n-1,W));
    }
    else
    {
        return knapsack(wt,val,n-1,W);
    }
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