class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& it, int t) {
        int n = it.size();
        vector<int>fb(n , 0);

        for (int i =0;i<n;i++){
            for(int j=0 ; j<n ;j++){
                if(i!=j &&it[i][0]!=0 && it[j][0] %it[i][0]==0){
                    fb[i]++;
                }
            }
        }
        vector<int>dp(t+1 , 0);
        for(int i = 0 ; i< n ; i++){
            int p =it[i][1];
            int fv = 1+fb[i];

            vector<int> ndp = dp;

            for(int w = p ; w<=t ;w++){
                ndp[w]=max(ndp[w] , dp[w-p]+fv);
            }
            for(int w = p ; w<=t ;w++){
                ndp[w]=max(ndp[w] , ndp[w-p]+1);
            }
            dp = move(ndp);
        }
        return dp[t];
    }
};