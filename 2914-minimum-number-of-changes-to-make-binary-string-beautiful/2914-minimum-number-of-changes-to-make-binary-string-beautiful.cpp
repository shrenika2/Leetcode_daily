class Solution {
public:
    int minChanges(string s) {
        // int n = s.size();
        // int ans1 = 0 ;
        // int ans2 = 0 ;
        // int e = 0 ;
        // int o = 0 ;
        // if(n==2){
        //     if((s[0]!= s[1]) && (s[1] != s[0])){
        //         return 1;
        //     }
        // }
        // for (int i = 0 ; i < n/2 ; i++){
        //     if(s[i]=='1'){
        //         o++;
        //     }
        // }
        // ans1 = min (o , abs(n/2 - o));
        // for (int i = n/2 ; i < n ; i++){
        //     if(s[i]=='1'){
        //         e++;
        //     }
        // }
        // ans2 = min( e ,abs(e - n/2));

        // return ans1 + ans2 ;


        int n = s.length();
        int cnt = 0 ;
        for (int i = 0 ; i < n-1 ; i+=2){
            if(s[i]!=s[i+1]){
                cnt++;
            }
        }
        return cnt ;
    }
};