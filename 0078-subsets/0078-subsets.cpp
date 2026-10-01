class Solution {
public:
    void gen(int idx , vector<int>&ds , vector<int>& nums , vector<vector<int>>&ans){
        if(idx == nums.size()){
            ans.push_back(ds);
            return ;
        }
        ds.push_back(nums[idx]);
        gen(idx+1 , ds , nums , ans);
        ds.pop_back();
        gen(idx+1 , ds , nums , ans );
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int>ds;
        gen(0 , ds , nums , ans );
        return ans ;
    }
};