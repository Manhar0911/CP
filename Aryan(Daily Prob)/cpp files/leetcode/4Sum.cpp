#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int g) {
        vector<vector<int>>res;
        long long target = g;
        int n = a.size();
        sort(a.begin(),a.end());
        set<vector<int>>ans;
        vector<int>v;
        for(int i=0;i<n;i++)
        {   
            target -= a[i];
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;    
                int s = j+1;
                int e = n-1;
                while(s<e)
                {
                    if(s==i)
                    {
                        s++;
                        continue;
                    }
                    if(e==i)
                    {
                        e--;
                        continue;
                    }
                    long long sum = a[j]+a[s];
                    sum += a[e];
                    if(sum==target)
                    {
                        v = {a[i],a[j],a[e],a[s]};
                        sort(v.begin(),v.end());
                        ans.insert(v);
                        s++;
                        e--;
                    }
                    else if(sum>target)
                    {
                        e--;
                    }
                    else
                    {
                        s++;
                    }
                }
            }
            target+=a[i];
        }
        
        for(auto x:ans)
        {
            res.push_back(x);
        }
        return res;
    }
};