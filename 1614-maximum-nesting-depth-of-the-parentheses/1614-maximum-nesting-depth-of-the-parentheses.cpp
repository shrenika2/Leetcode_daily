class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 0 ;
        int mx = 0 ;
        for (int i =0 ; i <n ; i++){
            if(s[i]=='('){
                cnt++;
                mx = max(mx , cnt);
            }else if (s[i] == ')'){
                cnt--;
            }
        }
        return mx ;
    }
};