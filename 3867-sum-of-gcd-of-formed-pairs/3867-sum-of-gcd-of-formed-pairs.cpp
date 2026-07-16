#include<bits/stdc++.h>
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long > pre;
       // vector<long long > mx;
        long long mxx = 0 ;
        for (auto it : nums){
            mxx = max(mxx , (long long) it);
            long long gcdd= __gcd((long long )it , mxx);
            pre.push_back(gcdd);
        }
        sort(pre.begin() , pre.end());
        long long  l = 0 ;
        long long  r = pre.size()-1;
        long long sm = 0 ;
        while(l<r){
            sm+=__gcd(pre[l] , pre[r]);
            l++;
            r--;
        }

        return sm;
    }
};