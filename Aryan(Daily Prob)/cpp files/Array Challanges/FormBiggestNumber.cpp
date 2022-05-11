/*

Problem Name: Form Biggest Number
Problem Difficulty: None
Problem Constraints: 1<=t<=100 <br>
1<=m<=100 <br>
1<=A[i]<=10^5
Problem Description:
You are provided an array of numbers. You need to  arrange them in a way that yields the largest value.


Input Format: First line contains integer t which is number of test case. <br>
For each test case, you are given a single integer n in the first line which is the size of array A[] and next line contains n space separated integers denoting the elements of the array A .

Sample Input: 1
4
54 546 548 60
Output Format: Print the largest value.

Sample Output: 6054854654

*/

#include <bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)
#define endl "\n"
#define ll long long int
#define pb(x) push_back(x)
#define fastio; ios_base::sync_with_stdio(false);cin.tie(NULL);
#define modulo 1000000007

bool compare(string s1, string s2)
{
   int l1 = s1.length();
   int l2 = s2.length();

   int l = min(l1,l2);
   f(i,0,l)
   {
       if(s1[i]>s2[i])
       return s1>s2;
       else if(s1[i]<s2[i])
       return s1<s2;
   }
   if(l1>l2)
   {
       if(s1[l]>s2[0])
       return s1>s2;
       else
       return s1<s2;
   }
   else if(l1<l2)
   {
      if(s1[0]<s2[l])
      return s1<s2; 
      else
      return s1>s2;
   }
   else
   {
       return s1>s2;
   }

}

int main()
{
    fastio;
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        f(i,0,n)
        {
            cin>>s[i];
        }
        sort(s,s+n,compare);
        f(i,0,n)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    
    return 0;
}


/*
=====Solution=====
// Given an array of numbers, program to arrange the numbers to form the
// largest number
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// A comparison function which is used by sort() in printLargest()
int myCompare(string X, string Y)
{
	// first append Y at the end of X
	string XY = X.append(Y);

	// then append X at the end of Y
	string YX = Y.append(X);

	// Now see which of the two formed numbers is greater
	return XY.compare(YX) > 0 ? 1: 0;
}

// The main function that prints the arrangement with the largest value.
// The function accepts a vector of strings
void printLargest(vector<string> arr)
{
	// Sort the numbers using library sort funtion. The function uses
	// our comparison function myCompare() to compare two strings.
	// See http://www.cplusplus.com/reference/algorithm/sort/ for details
	sort(arr.begin(), arr.end(), myCompare);

	for (int i=0; i < arr.size() ; i++ )
		cout << arr[i];
	cout<<"\n";
}

// driverr program to test above functions
int main()
{

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<string> arr;
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			string s;
			cin>>s;
			arr.push_back(s);
		}
		printLargest(arr);
	}
    return 0;
}
*/