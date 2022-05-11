#include<iostream>
using namespace std;

int find(int a[],int n,int key)
{
    int s= 0;
    int e = n-1;
    int m;
    while(s<=e)
    {
        m = (s+e)/2;
        if(a[m] == key)
        return m;
        else if(a[m]>=a[s])
        {
            if(a[m] >= key and a[s]<= key)
            e = m - 1;
            else
            s = m + 1;
        }
        else
        {
            if(a[m] <= key and a[e] >= key)
            s = m + 1;
            else
            e = m - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;

    cout<<find(a,n,key);
    return 0;
}