class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto it : r){
            int row = it[0];
            int col = it[1];
            mp[row].insert(col);
        }
        int res = (n - mp.size())*2;

        for (auto [r , c]: mp){
            auto ia=[&](int it){
                return c.find(it)==c.end();
            
        };

            bool ga = ia(2) && ia(3) && ia(4) && ia(5);
            bool gb = ia(4) && ia(5) && ia(6) && ia(7);
            bool gc = ia(6) && ia(7) && ia(8) && ia(9);
            
            if (ga && gc) {
                res += 2;
            } else if (ga || gb || gc) {
                res += 1;
            }
        }

        return res;
        
    }
};