#include<bits/stdc++.h>
using namespace std;


// TC:O(nlogn) SC:O(1)
class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        int n = v.size();
        int s= 0;
        int e = n-1;
        sort(v.begin(),v.end());
        auto it = v.begin();
        int cnt = 0;
        while(s<e)
        {
            if(v[s]+v[e]==k)
            {
                 s++;
                 e--;
                cnt++;
            }
            else if(v[s]+v[e]>k)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        return cnt;
    }
};

// TC:O(nlogn) SC:O(1)
class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        unordered_map<int,int>ump;
        int cnt=0;
        for(int i=0;i<v.size();i++)
        {
            int res = k - v[i];
            if(ump[res]){
                cnt++;
                if(ump[res] == 1) ump.erase(res);
                else ump[res]--;
            }
            else{
                ump[v[i]]++;
            }
        }
         return cnt; 
    }
};