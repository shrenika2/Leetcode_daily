#define ll long long
class Solution {
public:
    int n;
    int k;
    vector<long long> resultArray(vector<int>& nums, int k) {
        this->n=nums.size();
        this->k=k;
        for(int i=0;i<n;i++) nums[i]%=k;
        vector<ll>ans(k,0);

        vector<vector<ll>>dp(n,vector<ll>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][nums[i]%k]++;
            if(i>0){
                for(int r=0;r<k;r++){
                int rem=(r*nums[i])%k;
                dp[i][rem]+=dp[i-1][r];
            }
            }
        }
        for(int i=0;i<n;i++){
            for(int x=0;x<k;x++){
                ans[x]+=dp[i][x];
            }
        }
        return ans;
    }
};