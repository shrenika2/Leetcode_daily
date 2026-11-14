class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mn = INT_MAX;
        
        for (int i = 0 ; i < n ; i++){
            int sm = 0 ;
            for (int j = i ; j < n; j++){
                 sm+=nums[j];
                int len = j - i + 1 ;
               if(len>=l && len<=r && sm>0) mn = min(mn , sm);
            }
        }
        if(mn == INT_MAX) return -1 ;
        return mn ;
    }
};