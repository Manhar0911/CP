#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int h = 2*n;
    int a[h];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i<h;i++)
    {
        a[i] = a[i-n];
    }
    int l=0;
    int curr_sum=0;
    int max_sum = INT_MIN;
    for(int i=0;i<n+l;i++)
    {
       if(curr_sum + a[i] < 0)
       {
           curr_sum = 0;
           l = i+1;
       }
       else
       {
           curr_sum = curr_sum + a[i];
       }

       if(max_sum<curr_sum)
       {
           max_sum = curr_sum;
       }
    }
    cout<<max_sum<<endl;
    return 0;
}