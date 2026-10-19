class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n= nums.size();
        int f = -1 ;
        int l = -1 ;
        sort(nums.begin() , nums.end());
        for (int i = 0 ; i < n ; i++){
            if(nums[i]==target){
                f = i ;
                break;
            }
        }
        for (int i = n-1 ; i>= 0 ; i--){
            if(nums[i]==target){
                l = i ;
                break;
            }
        }
        vector<int> ans;
        if(f==-1 && l == -1) return ans ;
        for (int i = f ; i <= l ; i++){
            ans.push_back(i);
        }
        
        return ans;
    }
};