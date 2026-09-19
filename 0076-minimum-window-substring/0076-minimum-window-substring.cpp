class Solution {
public:
    bool contains(vector<int> &mpS , vector<int> &mpT){
        for (int i = 0 ; i < 256 ; i++){
            if(mpT[i]>mpS[i]){
                return false;
            }
        }
        return true ;
    }
    string minWindow(string s, string t) {
        vector <int> mpS(256 , 0);
        vector <int> mpT(256 , 0);

        for (char ch : t) mpT[ch]++;

        int left = 0 ;
        int right = 0 ;
        int len = INT_MAX;
        int st = 0 ;

        for (; right <s.length() ; right++){
            mpS[s[right]]++;

            while(contains(mpS , mpT)){
                if(right - left + 1 < len){
                    len = right - left + 1 ;
                    st = left ;
                }
                mpS[s[left]]--;
                left++;
            }
        }
        if(len==INT_MAX) return "";

        return s.substr(st , len);
    }
};