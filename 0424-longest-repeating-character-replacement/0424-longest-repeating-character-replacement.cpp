class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 ; 
        int r = 0 ;
        int res = -1 ;
        int freq = 0 ;
        map<int , int> mpp;
        while(r<s.length()){
            mpp[s[r]-'A']++;
            freq = max (freq , mpp[s[r]-'A']);
            int len = r - l + 1 ;

            if(len - freq > k){
                mpp[s[l]-'A']--;
                l++;
                len = r-l+1 ;
            }
            r++;
            res = max(res , len);
        }
        return res;
    }
};