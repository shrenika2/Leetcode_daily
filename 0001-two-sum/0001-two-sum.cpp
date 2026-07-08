// brute 
// tc = o(n^2)
// sc = o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0 ;
        while(i< n ){
            int req = target - nums[i];
            for (int j = i+1 ; j < n ; j++){
                if(nums[j]==req){
                    return {i , j};
                    break;
                }
            }
            i++;
        }
        return {};
    }
};
// optimal 
// tc = o(n)
// sc = o(n)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> mp;

//         for(int i = 0; i < nums.size(); i++) {
//             int req = target - nums[i];
//             if(mp.count(req))
//                 return {mp[req], i};
//             mp[nums[i]] = i;
//         }
//         return {};
//     }
// };