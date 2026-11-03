class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 ;
        int mx = *max_element(nums.begin() , nums.end());
        for (int i = 0 ; i < n ; i++){
            if(mx > nums[i]){
                ans+=(mx - nums[i]);
            }
        }
        return ans;
    }
};