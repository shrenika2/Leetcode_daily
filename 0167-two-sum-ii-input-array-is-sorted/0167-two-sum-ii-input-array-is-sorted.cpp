class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int s = 0 ;
        int l = n-1 ;
        while(s < l){
            if (numbers[s]+numbers[l] == target){
                return {s+1 , l+1};
            }
            else if (numbers[s]+numbers[l] < target){
                s++;
            }else{
                l--;
            }
        }
        return {};
    }
};