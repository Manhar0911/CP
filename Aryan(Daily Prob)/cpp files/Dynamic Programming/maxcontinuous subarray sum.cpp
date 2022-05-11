#include<bits/stdc++.h>
using namespace std;

int maxsubarraySum(int arr[], int n)
{
   int curr_sum=0;
   int max_sum = 0;
   for(int i=0;i<n;i++)
   {
       if(curr_sum + arr[i] > 0)
       curr_sum = curr_sum + arr[i];
       else
       curr_sum = 0;

       if(max_sum <= curr_sum)
       max_sum = curr_sum; 
   }
   if(max_sum == 0)
   {
       sort(arr,arr+n);
       return arr[n-1];
   }
   return max_sum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxsubarraySum(arr,n)<<endl;
    return 0;
}