class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        vector<int> res ;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++){
        if(nums[i]>9){
            int sm = 0 ;
        while(nums[i] > 0){
          
            int lt = nums[i] %10;
            sm += lt;
            nums[i]/=10;
        }
        res.push_back(sm);
        }else{
            res.push_back(nums[i]);
        }
        }
        for (int i = 0 ; i < n ; i++){
            if(res[i]==i){
                return i ;
            }
        }
        return -1 ;
    }
};