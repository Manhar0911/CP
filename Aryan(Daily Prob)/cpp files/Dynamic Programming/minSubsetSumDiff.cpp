#include<iostream>
#include<algorithm>
using namespace std;

#define f(i,n,m)  for(int i=n;i<m;i++)

// Time complexity n*w
int minSubsetSumDiff(int arr[],int n)
{
    int sum = 0;
    f(i,0,n)
    sum += arr[i];
    
    bool t[n+1][sum+1];
    //initialization
    
    f(i,0,n+1)
    {
        f(j,0,sum+1)
        {
            if(i==0)
            t[i][j] = false;
            if(j==0)
            t[i][j] = true;
        }
    }
   
   f(i,1,n+1)
   {
       f(j,1,sum+1)
       {
           if(arr[i-1]<=j)
           {
               t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
           }
           else
           {
               t[i][j] = t[i-1][j];
           }
       }
   }
    
    for(int j=sum/2;j>=0;j--)
    {
        if(t[n][j] == true)
        return sum-2*j;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    f(i,0,n)
    {
        cin>>arr[i];
    }
    cout<<minSubsetSumDiff(arr,n);
    return 0;
}