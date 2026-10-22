// your code goes here ........................
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int s = -1 ;
        for (int i=0;i<n;i++){
            if(nums[i]==0){
                s=i;
                break;
            }
        }bool sh = true ;
        for (int i = 0 ;i <n ;i++){
            if(nums[(s+i)%n]!=i){sh=false;break;}
        }
        bool shh = true ;
        for(int i=0;i<n;i++){
            if(nums[(s-i+n)%n]!=i){
                shh=false;
                break;
            }
        }
        int mn=1e9;
        if(sh){mn=min(mn , min(s , n-s+2));}
        if(shh){mn=min(mn , min(n-s,s+2));}
        if(mn==1e9){return -1;}
        return mn;
        
    }
};