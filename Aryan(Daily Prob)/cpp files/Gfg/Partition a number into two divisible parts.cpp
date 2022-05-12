#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string stringPartition(string s, int a, int b){
        // code here 
        int slen = s.size();
       string s1,s2;
       
       for(int i = 1; i < slen; i++)
       {
           s1 = s.substr(0,i);
           s2 = s.substr(i,slen);
           long long dividend_a = stoi(s1);
           long long dividend_b = stoi(s2);
           
           if( dividend_a % a == 0 && dividend_b % b == 0 )
           {
               string ans = s1 + ' ' + s2;
               return ans;
           }
           
       }
       return "-1";
    }
};
