#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],l[n],r[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    l[0] = a[0]; 
    r[n-1] = a[n-1];
    int water=0;
    for(int i=1;i<n;i++)
    {
       l[i] = max(l[i-1],a[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
       r[i] = max(r[i+1],a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if( (min(l[i],r[i]) - a[i] )> 0)
        water = water + min(l[i],r[i]) -a[i];
    }
    cout<<water<<endl;
    return 0;
}