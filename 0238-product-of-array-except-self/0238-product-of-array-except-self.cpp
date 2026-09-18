class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        left[0]=1;
        left[1]=nums[0];
        for (int i = 2 ; i < n ; i++){
            left[i]=nums[i-1]*left[i-1];
        }
        vector<int> right(n);
        right[n-1]=1 ;
        right[n-2]=nums[n-1];
        for (int i = n-3 ; i >= 0 ; i--){
            right[i]=right[i+1]*nums[i+1];
        }
        vector<int> ans(n);
        for (int i = 0 ; i < n ; i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};