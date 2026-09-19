class Solution {
public:
    int lengthOfLongestSubstring(string sr) {
        int n = sr.length();
        int s = 0 ;
       
        int cnt = 0;
        int mx = 0;
        unordered_set<char>st;
        for (int e = 0 ; e < n ; e++){
            while(st.find(sr[e])!=st.end()){
                st.erase(sr[s]);
                cnt--;
                s++;
            }
                st.insert(sr[e]);
                cnt++;
                mx = max(mx , cnt ); 
            } 
        
        return mx;
    }
};