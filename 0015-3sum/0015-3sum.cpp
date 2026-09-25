class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0 ; i < n-2 ; i++){
             if(i > 0 && nums[i]==nums[i-1]) continue;
     
            if(nums[1]>0) break;
            int f = i+1 ;
            int l = n-1 ;
            while(f <l){
                int sum = nums[i]+nums[f]+nums[l];
               if(sum == 0){
                    res.push_back({nums[i] , nums[f] , nums[l]});
                     if( f <l && nums[f]==nums[f+1]) f++;
                if( f<l && nums[l]==nums[l-1]) l--;
                    f++;
                    l--;
                }else if (sum < 0){
                    f++;
                }else {
                    l--;
                }
               
                
            }
          
        }
          return res;
    }
};