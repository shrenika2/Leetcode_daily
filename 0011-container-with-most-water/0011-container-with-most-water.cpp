class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int s = 0 ;
        int l = n-1;
        int mx = INT_MIN;
        while (s < l){
            mx = max(mx , (l-s) * min (h[s] , h[l]));

            if (h[s]>h[l]) l--;
            else s++;
        }
        return mx;
    }
};