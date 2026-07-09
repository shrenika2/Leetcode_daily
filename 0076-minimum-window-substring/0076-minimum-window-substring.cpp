class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = t.size();
        int l = 0 , r = 0 ;
        int st = 0 ;
        int mn = INT_MAX;
        map<int , int> mp;
        for (auto it : t){
            mp[it]++;
        }
        while (r < s.size()){
            if(mp[s[r]]>0){
                cnt --;
            }
                mp[s[r]]--;
                r++;
                while (cnt == 0) {
                if (r - l < mn) {
                    mn = r - l;
                    st = l;
                }

                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt++;
                }l++;
            }
        }
        
       return mn == INT_MAX ? "" : s.substr(st, mn);
    }
};