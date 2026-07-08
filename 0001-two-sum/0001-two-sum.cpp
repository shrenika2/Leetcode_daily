class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0 ;
        while(i< n ){
            int req = target - nums[i];
            for (int j = i+1 ; j < n ; j++){
                if(nums[j]==req){
                    return {i , j};
                    break;
                }
            }
            i++;
        }
        return {};
    }
};