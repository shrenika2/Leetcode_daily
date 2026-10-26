class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n= og[0].size();
        vector<vector<int>>dp(m, vector<int>(n , 0));
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if(og[i][j]==1) continue ;
                if (i == 0 && j == 0 ){
                    dp[i][j]=1;
                }else{
                    if(i>0) dp[i][j]+=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }
            }
           
        }
         return dp[m-1][n-1];
    }
};