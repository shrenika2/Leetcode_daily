class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sm = nums[0];
        int idx = 0 ;
        for (int i = 1; i < n ; i++){
            if( nums[i]==nums[i-1]+1){
                sm+=nums[i];
                // idx = i ;
            }else{
                break;
            }
        }
        while (find(nums.begin(), nums.end(), sm) != nums.end())
            sm++;

        return sm;
    }
};