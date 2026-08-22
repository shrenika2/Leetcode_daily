class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 ;
        int pro = 1 ;
        int nw = n;
        while(nw>0){
            int lt = nw%10;
            sum+=lt ;
            pro*=lt;
            nw/=10;
        }
        int smmm = sum + pro;

        int rem = n % smmm;

        return rem == 0 ? true : false;
    }
};