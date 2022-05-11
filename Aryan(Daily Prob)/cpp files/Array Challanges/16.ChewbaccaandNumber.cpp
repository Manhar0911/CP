/*

Problem Name: Chewbacca and Number
Problem Difficulty: 1
Problem Constraints: x <= 100000000000000000
Problem Description:
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

Input Format: The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.
Sample Input: 4545
Output Format: Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.
Sample Output: 4444

*/

#include <bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)
#define endl "\n"
#define ll long long int
#define pb(x) push_back(x)
#define fastio; ios_base::sync_with_stdio(false);cin.tie(NULL);
#define modulo 1000000007


int main()
{
    fastio;
    ll n;
    cin>>n;
    //ll x = n;
    int i=0;
    int arr[20];
    while(n>0)
    {
       arr[i] = n%10;
       n = n/10;
       i++;
    }
    int l = i;
    int ans=0;
    while(i--)
    {
       if(arr[i]>= 5)
       {
           if(arr[i]==9 && i+1==l)
           {
               // do nothing
           }
           else
           {
               arr[i] = 9 - arr[i];
           }
       }
       ans = ans*10 + arr[i];
    }
    cout<<ans;
    return 0;
}
