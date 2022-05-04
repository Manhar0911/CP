//cout<<setprecision(digits)<<varname<<endl;
#include<bits/stdc++.h>
#define endl "\n" ;
#define ll long long int 
using namespace std ;

vector<vector<string>> fun(vector<vector<string>> &v  ,int r) // r is rows
{
	if(r == 1)	return v ;

	//we take last two rows i.e r-1 and r-2 andcombine them 
	vector<string> vv ;
	string ss ,st;
	int s = v[r-2].size(),s2 = v[r-1].size() ;
	for(int i =0 ; i < s  ;i++)
	{
		ss = v[r-2][i] ;
		for(int j=0;j<s2 ; j++)
		{
			st = ss + " " + v[r-1][j] ;
			vv.push_back(st);
		}
	}
	v[r-2] = vv ;
	return fun(v,r-1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool f ;
	int t,n,k,c,m,i,j,ans,x,y ;
	string s;
	cin>>t ; // total rows 
	vector<vector<string>> v(t) ;
	for(i=0;i<t;i++)
	{
		//cout<<"Yes\n";
		cin>>n ;
		for(j=0;j<n;j++)
		{
			cin>>s;
			v[i].push_back(s);
		}
	}
	//input done
	//use recusrion to print all 
	v = fun(v,t) ;
	n = v[0].size() ;
	
	for(i=0;i<n;i++)
		cout<<v[0][i]<<endl ;
	
	return 0;
}