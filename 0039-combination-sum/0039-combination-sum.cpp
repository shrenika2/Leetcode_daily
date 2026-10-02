class Solution {
public:
    vector<vector<int>> ans ;
    int n ;
     void solve(vector<int> &temp , vector<int> &candidates , int target , int i){
        if (target == 0){
            ans.push_back(temp);
            return ;
        }
        if(i==n || target < 0){
            return ;
        }
       
            temp.push_back(candidates[i]);
            solve(temp , candidates , target - candidates[i] , i);
            temp.pop_back();
            solve(temp , candidates , target , i+1);
        
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int>temp ;
        solve(temp , candidates , target , 0);
        return ans ;
        
    }
};