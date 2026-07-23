class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1 || n==2){
            return n ;
        }
        
        int ans = 0 ;
        for (int i = 0 ; i < 30 ; i++){
            if(n< pow(2 ,i)){
                ans = pow(2 ,i);
                break;
            }
        }
        return ans ;
    }
};