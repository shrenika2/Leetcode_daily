class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin() , nums.end());

        int t = 1 ;
        while(t<= mx){
            t= t*2; // t<<=1;
        }
        if(n==1) return n;
        vector<bool> s1(t, false);
        vector<bool> anss(t, false);
        
        for (int i = 0 ; i < n ; i++){
            for (int j = i ; j < n ; j++){
                s1[nums[i]^nums[j]] = true;
            }
        }
        
        for (int i = 0; i < t; i++) {
            if (s1[i]) {
                for(auto it : nums){
                    anss[i ^ it] = true;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < t; i++) {
            if (anss[i]) cnt++;
        }
        return cnt;
    }
};