class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int cnt = 0 , a = 0 ;
        for (char ch: s){
            if(ch == '('){
                cnt++;
            }else{
                if(cnt>0){
                    cnt--;
                }else{
                    a++;
                }
            }
        }
        return a + cnt ;
    }
};