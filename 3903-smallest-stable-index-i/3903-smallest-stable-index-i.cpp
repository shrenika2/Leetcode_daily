class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1 ;

        vector<int> ps(n) , ss(n);
        ps[0]=nums[0];
        ss[n-1]=nums[n-1];
        for (int i = 1 ; i < n ; i++){
            ps[i]=max(ps[i-1] , nums[i] );
        }
        for (int j = n-2 ; j>=0 ; j--){
            ss[j]=min(ss[j+1]  , nums[j]);
        }
        for (int i = 0 ; i < n ; i++){
            int s = ps[i]-ss[i];
            if (s <= k){
                ans = i ;
                break;
            }
        }
        return ans ;
    }
};