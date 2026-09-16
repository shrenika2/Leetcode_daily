class Solution {
    const int MOD = 1000000007;
    int dp[1001][1001][3];

    int go(int i, int rem, int flag, int n){
        if(rem < 0) return 0;
        if(i == n) {
            if((flag == 0 && rem == 0) || (flag == 2 && rem == 1)) return 1;
            return 0;
        }

        int &ret = dp[i][rem][flag];
        if(~ret) return ret;

        ret = 0;
        if(flag == 0){ // not in a line segment
            ret = (ret + go(i + 1, rem, flag, n)) % MOD; // continue
            if(rem) ret = (ret + go(i + 1, rem, 1, n)) % MOD; // start a new line
        }
        else if(flag == 1){ // there is a line started from previous point
            ret = (ret + go(i + 1, rem, 2, n)) % MOD; // mark that this line is valid
        }
        else{ // valid line
            ret = (ret + go(i + 1, rem, 2, n)) % MOD; // continue with the line
            ret = (ret + go(i, rem - 1, 0, n)) % MOD; // end the line in the previous point
            if(rem) ret = (ret + go(i, rem - 1, 1, n)) % MOD; // end the line in the previous point and start a new one
        }

        return ret;
    }

public:
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return go(0, k, 0, n);
    }
};