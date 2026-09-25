class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int sr = 0 ;
        int l = 0;
        unordered_set<int> st;
        int mx = 0;
        while(l < n){
            if(!st.count(s[l])){
                st.insert(s[l]);
                l++;
                mx = max(mx , l-sr);
            }else{
                st.erase(s[sr]);
                sr++;
            }

        }
        return mx;
    }
};