/*

Problem Name: Arrays-Spiral Print Anticlockwise
Problem Difficulty: None
Problem Constraints: Both M and N are between 1 to 10.
Problem Description:
Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format: Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).
Sample Input: 4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Output Format: All M * N integers separated by commas with 'END' written in the end(as shown in example).
Sample Output: 11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END

*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vll vector<long long int>
#define vld vector<long double>
#define pll pair<long long int,long long int>
#define f(i,n,m) for(int i=n;i<m;i++)
#define ll long long int
#define ld long double
#define pi 3.141592653589793238
#define Endl endl
#define endl "\n"

int main()
{
    FAST;
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    f(i,0,m)
    {
        f(j,0,n)
        {
            cin>>arr[i][j];
        }
    }
   /* f(i,0,m)
    {
        f(j,0,n)
        {
            cout<<arr[i][j];
        }
    }
    */
    int left,right,up,down;
    left = 0;
    right = n-1;
    up = 0;
    down = m-1;
    int i=0,j=0;
    while(1)
    {
        if(i==left && j == up)
        {
            while(i<=down)
            {
                cout<<arr[i][j]<<", ";
                i++;
            }
            left++;
            i--;
            j++;
        }
        
        if(left > right || up > down)
        break;
        
        if(j == left && i == down)
        {
            while(j<=right)
            {
                cout<<arr[i][j]<<", ";
                j++;
            }
            down--;
            j--;
            i--;
        }
        
        if(left > right || up > down)
        break;
        
        if(j == right && i == down)
        {
            while(i>=up)
            {
                cout<<arr[i][j]<<", ";
                i--;
            }
            right--;
            i++;
            j--;
        }
        
        if(left > right || up > down)
        break;
        
        if(j== right && i ==up)
        {
            while(j>=left)
            {
                cout<<arr[i][j]<<", ";
                j--;
            }
            up++;
            j++;
            i++;
        }
        if(left > right || up > down)
        break;

        //break;
    }
    cout<<"END"<<endl;
    return 0;
}
