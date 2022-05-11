#include<iostream>
#include<algorithm>
using namespace std;

#define f(i,n,m)  for(int i=n;i<m;i++)

// Time complexity n*w
int cntSubsetSum(int arr[],int n,int sum)
{
    int t[n+1][sum+1];
    //initialization
    
    f(i,0,n+1)
    {
        f(j,0,sum+1)
        {
            if(i==0)
            t[i][j] = 0;
            if(j==0)
            t[i][j] = 1;
        }
    }
   
   f(i,1,n+1)
   {
       f(j,1,sum+1)
       {
           if(arr[i-1]<=j)
           {
               t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
           }
           else
           {
               t[i][j] = t[i-1][j];
           }
       }
   }
    
    return t[n][sum];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    f(i,0,n)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    int diff;
    cin>>diff;
    int s = (sum-diff)/2;
    cout<<cntSubsetSum(arr,n,s);
    return 0;
}