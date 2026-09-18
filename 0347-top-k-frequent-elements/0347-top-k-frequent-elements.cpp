class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> freq ;

        for (auto c : nums){
            freq[c]++;
        }

        vector<vector<int>> buc(n+1);


        for (auto& [num , fre] : freq){
            buc[fre].push_back(num);
        }
        vector<int> res ;
        for (int i = n ; i >= 1 && res.size()<k ; i--){
            for (int c : buc[i]){
                res.push_back(c);

                if(res.size()==k){
                    break;
                }
            }
        }
        return res;
    }
};