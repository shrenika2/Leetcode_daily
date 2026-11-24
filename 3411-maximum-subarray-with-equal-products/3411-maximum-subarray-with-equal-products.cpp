class Solution {
public:
#define ll long long 
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 ;
        for (int i = 0 ; i < n ; i++){
            ll p = 1 ;
            ll g = 0 ;
            ll l = 1 ;

            for (int j = i ; j < n ; j++){
                p *= nums[j];
                g = gcd(g , (ll)nums[j]);
                l = lcm(l , (ll)nums[j]);

                if(p == l * g){
                    ans = max(ans , j-i+1);
                }
                if(p > 25200) break;
            }
        }
        return ans ;
    }
};