class Solution {
public:
    int dp[101];
    int solve(vector<int> &nums , int i){
        int n = nums.size();
        if(i>=nums.size()) return 0 ;
        if(dp[i]!=-1){
            return dp[i];
        }
        int steal = nums[i]+solve(nums , i+2);
        int skip = solve(nums , i+1);
        
        return dp[i]=max(steal , skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(nums , 0);
    }
};