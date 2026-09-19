class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> >ans ;

        sort(nums.begin() , nums.end());

        for (int i = 0 ; i < n-2 ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue ;

            int f = i+1 ;
            int l = n-1;

            while(f < l){
                int ex = (nums[i]+nums[f]+nums[l]);

                if(ex==0) {
                    ans.push_back({nums[i] , nums[f] , nums[l]});

                    while(f < l && nums[f]==nums[f+1]) f++;
                    while(f < l & nums[l]==nums[l-1]) l--;

                    f++;
                    l--;
                }else if(ex<0){
                    f++;
                }else{
                    l--;
                }
            }
        }
        return ans ;
    }
};