#include<bits/stdc++.h>
using namespace std;

int mincoinused(int arr[],int sum,int n)
{
    int cnt=0;
   while(sum>0)
   {
       if(sum>=1000)
       {
          cnt = cnt + sum/1000;
          sum = sum % 1000;
       }
       else
       {
          auto lb = lower_bound(arr,arr+n,sum);
          if(*lb == sum)
          {
              cnt++;
              sum = 0;
          }
          else
          {
              int num = *(lb-1);
              cnt = cnt + sum/num;
              sum = sum % num;
              //cout<<num<<sum <<cnt<<" ";
          }
       }
   }
   return cnt;
}

int main()
{
    int arr[] = {1,2,5,10,20,50,100,200,500,1000};
    int sum ;
    cin>>sum;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<mincoinused(arr,sum,n);
    return 0;
}