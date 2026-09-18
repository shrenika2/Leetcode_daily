class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int pro = 1 ;
        for (int i = 0 ; i < nums.size() ; i++){
            pro*=nums[i];
            mx = max(mx , pro);
            if(pro==0) pro = 1 ;
        }
        pro = 1 ;
        for (int j = nums.size()-1 ; j >= 0 ; j--){
            pro*=nums[j];
            mx = max(mx , pro);
            if(pro==0) pro = 1 ;
        }
        return mx ;
    }
};