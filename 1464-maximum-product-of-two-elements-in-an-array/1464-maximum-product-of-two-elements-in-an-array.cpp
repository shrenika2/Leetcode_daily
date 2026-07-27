class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n ;

        sort(nums.begin() , nums.end());
        int ans = (nums[n-1]-1) * (nums[n-2]-1);
        return ans ;
    }
};