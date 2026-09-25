class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s = 0 ;
        int l = n-1 ;
        int mx = 0 ;
        while(s < l){
            int width = l - s ;
            mx = max(mx , width * min(height[s] , height[l]));
            if(height[s]<height[l]){
                s++;
            }else if (height[s] > height[l]){
                l--;
            }else{
                s++;
                l--;
            }
        }
        return mx ;
    }
};