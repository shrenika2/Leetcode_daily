class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();

        if(n==1){
            if(s1[0]==s2[0]) return 0 ;
            if(s1[0]=='0' && s2[0]=='1') return 1;
            return -1 ;
        }

        int op = 0 ;

        for (int i = 0 ; i < n-1 ; i++){
            if(s1[i]==s2[i]) continue ;

            if(s1[i]=='0'){
                op++;
            }else{
                if(s1[i+1]=='1'){
                    op++;
                    s1[i+1]='0';
                }else{
                    op+=2;
                }
            }
        }

        if(s1[n-1]!=s2[n-1]){
            if(s1[n-1]=='0'){
                op++;
            }else{
                op+=2;
            }
        }
        return op;
        
    }
};