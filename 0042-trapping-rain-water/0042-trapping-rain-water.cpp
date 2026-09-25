class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmx = 0;
        int rmx = 0 ;
        int left = 0 ;
        int right = n-1 ;
        int w = 0 ;
        while (left < right){
            if(height[left]<=height[right]){
            lmx = max(lmx , height[left]);
            if(lmx>=height[left]){
            w+=(lmx-height[left]);
            left++;
            }
            }else{
                rmx = max(rmx , height[right]);
                if(rmx>=height[right]){
                w+=(rmx-height[right]);
                right--;
            }}
            
        }
        return w;
        
    }
};