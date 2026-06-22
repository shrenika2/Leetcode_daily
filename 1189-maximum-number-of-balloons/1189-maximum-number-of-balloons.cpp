class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> f(26);
        for (auto it : text){
            f[it-'a']++;
        }
    return min({f['b'-'a'] , f['a'-'a'] , (f['l'-'a'])/2 , (f['o'-'a'])/2 , f['n'-'a']});
    }
};