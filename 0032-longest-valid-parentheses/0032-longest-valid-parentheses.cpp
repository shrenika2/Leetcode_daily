class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int mx = 0 ;
        int cnt = 0 ;
        int o = 0 ;
        cnt = 0;
        o = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
                o++;
            } else {
                cnt--;
                o++;
            }

            if (cnt < 0) {
                cnt = 0;
                o = 0;
            }

            if (cnt == 0) {
                mx = max(mx, o);
            }
        }

        cnt = 0;
        o = 0;

        for (int i = n-1 ; i >= 0 ; i--){
            if(s[i]==')'){
                cnt++;
                o++;
           
            }else{
                cnt--;
                o++;
            }
            if (cnt < 0) {
                cnt = 0;
                o = 0;
            }
            if(cnt == 0){
                mx = max(mx , o);
            }
        }
        return mx ;
    }
};