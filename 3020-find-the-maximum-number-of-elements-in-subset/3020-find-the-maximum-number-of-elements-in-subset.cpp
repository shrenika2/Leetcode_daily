class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long , int>f;
        for (int x : nums) f[x]++;

        int ans = 1 ;

        if(f.count(1)){
            if(f[1]%2==0){
                ans = max(ans , f[1]-1);
            }else{
                ans = max(ans , f[1]);
            }
        }

        for(auto &[x , cnt] : f){
            if(x==1) continue;

            long long curr = x;
            int len = 1;

            while(f[curr]>= 2){
                 if (curr > 1000000000LL) break;   // prevents overflow
                long long nxt = curr * curr;
                if (!f.count(nxt)) break;
                len += 2;
                curr = nxt;
            }
           ans = max(ans, len);
        }
        return ans ;
    }
};