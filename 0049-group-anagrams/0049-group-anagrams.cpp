class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string , vector<string>>mp;
        for(auto it : strs){
            string itt = it;
            sort(itt.begin() , itt.end());
            mp[itt].push_back(it);
        }
        vector<vector<string>> res ;
        for (auto it : mp){
            res.push_back(it.second);
        }
        return res ;
    }
};