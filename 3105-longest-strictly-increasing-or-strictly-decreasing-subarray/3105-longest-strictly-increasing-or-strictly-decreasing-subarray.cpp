class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 1 , cnt = 1 ;
        for (int i = 1 ; i < n ; i++){
            if(nums[i]>nums[i-1]){
                cnt++;
                mx = max(mx , cnt);
            }else{
                cnt = 1 ;
            }
        }
        cnt = 1;
        for (int i = 1 ; i < n ; i++){
            if(nums[i]<nums[i-1]){
                cnt++;
                mx = max(mx , cnt);
            }else{
                cnt = 1 ;
            }
        }
        return mx ;
        
    }
};