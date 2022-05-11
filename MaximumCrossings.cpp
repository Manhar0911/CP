//cout<<fixed<<setprecision(digits)<<varname<<endl;
#include<bits/stdc++.h>
#define endl "\n" ;
#define ll long long int 
using namespace std ;


ll merge(int a[],int l,int m, int r,int n)
    {
        ll cnt=0;
        int i=l;
        int j=m+1;
        int k=l;
        int temp[n];
        while(i<=m && j<=r)
        {
            if(a[i]>=a[j])
            {
                temp[k++] = a[j++];
                cnt = cnt + m-i+1;
            }
            else 
            temp[k++] = a[i++];
        }
        while(i<=m)
        temp[k++] = a[i++];
        while(j<=r)
        temp[k++] = a[j++];
        
        for(int i=l;i<=r;i++)
        {
            a[i] = temp[i];
        }
        return cnt;
    }
ll count(int arr[],int l,int r ,int n)
    {
        if(l>=r)
        return 0;
        
        long long int mid = (l+r)/2;
        
        ll ls = count(arr,l,mid,n);
        ll rs = count(arr,mid+1,r,n);
        ll k = merge(arr,l,mid,r,n);
        return ls+rs+k;
    }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,n,k,m,i,j,x,y,q ,l,r, ts;
	string s;
	cin>>t;
	while(t--) //another version of count inversionss 
	{	
		cin>>n;
		int arr[n] ;
		for(i=0;i<n;i++)	cin>>arr[i] ;
		cout<<count(arr,0,n-1,n)<<endl;
	}
	return 0 ;
}