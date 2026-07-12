class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> d = arr;
        sort(d.begin() , d.end());
        map<int , int> mp;
        int id = 1 ;
        for(auto it : d){
            if(!mp.count(it)){
                mp[it]=id++;
            }
        }

        vector<int> ans;
        for(auto it : arr){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};