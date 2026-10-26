class Solution {
public:
vector<vector<int>> dp;
    bool solve(int i , vector<int> &nums , int target){
        if(target==0){
            return true ;
        }
        if(i<0) return false;
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool take = false;
        if(nums[i]<=target){
        take = solve(i-1 , nums , target-nums[i]);
        }
        int skip = solve(i-1 , nums , target);
        return dp[i][target]=(take||skip);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ;
        for (int i = 0 ; i < n ; i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;

        dp.assign(n , vector<int>(target+1 , -1));
         return solve(n-1 , nums , target);

        
    }
};