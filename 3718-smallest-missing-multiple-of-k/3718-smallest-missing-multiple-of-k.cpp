class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> st ;
        set<int> st2 ;
        int n = nums.size();
        int mx = *max_element(nums.begin() , nums.end());
        int a = mx / k ;
        if(n==1 && nums[0]==k) return k*2;
        st.push_back(k);
        for (int i = 1 ; i <= 101 ; i++){
            st.push_back(k*i);
            
        }
        for (int i = 0 ; i < n ; i++){
            st2.insert(nums[i]);
        }
        sort(nums.begin() , nums.end());
        for (int i = 0 ; i <= 101 ; i++){
        if(!st2.count(st[i])) return st[i];
        }
        return -1 ;
    }
};