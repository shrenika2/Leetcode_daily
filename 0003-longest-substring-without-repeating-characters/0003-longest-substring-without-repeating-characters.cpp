class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char>st;
        int l = 0;
        int mx = 0 ;
        for (int r = 0 ; r < s.size() ; r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            mx = max(mx , r-l+1);
        }
        return mx;
    }
};

//Time = O(n), Space = O(min(n, charset))