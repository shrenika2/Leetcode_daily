class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int mx = 0 , s = -1 ;
        unordered_map<int , int> freq;

        for (int e = 0 ; e<nums.size() ; e++){
            freq[nums[e]]++;
            while(freq[nums[e]]>k){
                s++;
                freq[nums[s]]--;
            }
            mx = max(mx , e - s);
        }
        return mx ;
    }
};