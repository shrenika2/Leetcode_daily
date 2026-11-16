class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        int sm = 0 ;
        string nw = "";
        while (s.size()>k){
            for (int i = 0 ; i < s.size(); i+=k){
                sm = 0 ;
                for (int j = i ; j < min((int)s.size(),i+k) ; j++){
                    sm+=s[j]-'0';
                }
                nw+=to_string(sm);
            }
            s = nw;
            nw="";
        }
        return s ;
    }
};



