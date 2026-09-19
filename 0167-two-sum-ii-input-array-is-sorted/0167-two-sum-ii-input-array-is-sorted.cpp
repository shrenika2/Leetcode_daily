class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int st = 0 ;
        int lt = num.size()-1;
        while(st < lt ){
            if(num[st] + num[lt]  == t ){
                return {st+1 , lt+1};
            }else if (num[st] + num[lt] < t){
                st++;
            }else{
                lt--;
            }
        }
    return{};
    }
};