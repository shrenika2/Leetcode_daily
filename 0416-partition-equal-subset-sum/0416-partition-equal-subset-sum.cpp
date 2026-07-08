// class Solution {
// public:
//     bool solve(vector<int>&nums , int i , int target){
//         if(target==0){
//             return true;
//         }
//         if(i==nums.size()||target<0){
//             return false;
//         }
//         return solve(nums , i+1 , target-nums[i]) || solve(nums , i+1 , target);
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sm = 0 ;
//         for (auto it : nums){
//             sm+= it;
//         }
//         if(sm%2!=0) return false;
        
//         return solve(nums , 0 , sm/2);
//     }
// };


class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sm = 0 ;
        for (auto it : nums){
            sm+= it;
        }
        if (sm % 2 != 0)
        return false;
        int t = sm/2;
        vector<bool>dp(t+1 , 0);

        dp[0]=1;
        for (int x : nums){
            for (int j = t ; j>=x ; j--){
                dp[j]=dp[j]||dp[j-x];
            }
        }
        return dp[t];
    }
};


// Complexity
// Time: O(n × target)
// Space: O(target)