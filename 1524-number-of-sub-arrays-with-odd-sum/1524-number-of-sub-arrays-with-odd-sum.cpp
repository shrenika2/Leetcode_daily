class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       int MOD = 1e9+7;
        int n = arr.size();
        int e = 1 ;
        int o = 0 ;
        vector<int> pref(n+1) ;
        pref[0]=arr[0];
        for (int i = 1 ; i < n ; i++){
            pref[i]+=pref[i-1]+arr[i];
        }
        int cnt = 0 ;
        for (int i = 0 ; i < n ; i++){
            if(pref[i]%2==0){
                cnt= (cnt+o) %MOD;
                e++;
            }else{
                cnt = (cnt+e)%MOD;
                o++;
            }
        }
        return cnt ;

    }
};