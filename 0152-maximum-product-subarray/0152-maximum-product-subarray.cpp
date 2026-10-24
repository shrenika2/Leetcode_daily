class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int pro = 1 ;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++ ){
            pro *= nums[i];
            mx = max(mx , pro);
            if(pro == 0) pro = 1 ;
        }
        pro = 1 ;
        for (int i = n-1 ; i >= 0 ; i--){
            pro *= nums[i];
            mx = max(mx , pro);
            if(pro == 0) pro = 1;
        }
        return mx ;
    }
};