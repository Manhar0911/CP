#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>n;
        cin>>s;
        int ans =0;
        int i;
        for(i=0;i<n-1;i++)
        {
            if(s[i]== s[i+1])
            {
                cout<<"YES"<<endl;
                 break;
            }
        }
        if(i==n-1)
        cout<<"NO"<<endl;
    }
}