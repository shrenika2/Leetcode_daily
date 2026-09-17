class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false ;
        int cntS[26]={0};
        int cntT[26]={0};
        for (char c : s){
            cntS[c-'a']++;
        }
        for(char c : t){
            cntT[c-'a']++;
        }
        return memcmp(cntS , cntT , sizeof(cntS))==0;
        
    }
};