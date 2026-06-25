class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0 ;

        for (int i = 0 ; i < n ; i++){
            int f = 0 ;
            for (int j = i ; j < n ; j++){
                if(nums[j]==target) f++;

                int len = j - i +1;

                if(f > len/2){
                    ans++;
                }
            }
        }
        return ans ;
    }
};