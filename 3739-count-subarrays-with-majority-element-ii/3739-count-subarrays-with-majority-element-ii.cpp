#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        // Map to store the frequency of each cumulative sum
        std::unordered_map<int, int> mp;
        
        int cumulative_sum = 0;
        // The cumulative sum is 0 before parsing the array, which we've seen once
        mp[0] = 1;
        
        long long valid_left_points = 0;
        long long result = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == target) {
                // If it's the target element, it adds +1 to cumulative sum.
                // We add the count of previous cumulative sums less than the new sum.
                valid_left_points += mp[cumulative_sum];
                cumulative_sum += 1;
            } else {
                // If it's not the target element, it subtracts -1 from cumulative sum.
                cumulative_sum -= 1;
                // We must subtract the frequency of the new cumulative sum because 
                // it is no longer strictly smaller than our updated sum.
                valid_left_points -= mp[cumulative_sum];
            }
            
            // Increment the count of the current cumulative sum in the map
            mp[cumulative_sum] += 1;
            // Add the valid left endpoints ending at the current position to the result
            result += valid_left_points;
        }
        
        return result;
    }
};