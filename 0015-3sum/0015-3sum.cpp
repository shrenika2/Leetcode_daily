// class Solution {
// public:
// #define ll  long long
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> st;
//         //unordered_map<ll , ll> mp;
       
        
//         for (int i = 0 ; i < n ; i++){
//             unordered_map<int, int> mp;
//             for (int j = i+1 ; j < n ; j++){
//                 int req = -1*(nums[i]+nums[j]);
//                if(mp.count(req)){
//                    vector<int> t = {nums[i], nums[j], req};
//                    sort(t.begin() , t.end());
//                    st.insert(t);
//                }
//                mp[nums[j]]=j;
//             }
//         }
//         return vector<vector<int>>(st.begin(), st.end()) ;
//     }
// };
// Complexity
// Time: O(n² log M) (because of set insertion)
// Space: O(n + M)

class Solution {
public:
#define ll  long long
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;

        for (int i = 0 ; i < n-2 ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1;
            int r = n-1;

            while(l<r){
                int sm = nums[i]+nums[l]+nums[r];

                if(sm==0){
                    ans.push_back({nums[i] , nums[l] , nums[r]});
                    l++;
                    r--;

                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1]){
                        r--;
                    }
                }else if(sm<0){
                    l++;
                }else{
                    r--;
                }
            }
        }

    return ans ;
    }
};