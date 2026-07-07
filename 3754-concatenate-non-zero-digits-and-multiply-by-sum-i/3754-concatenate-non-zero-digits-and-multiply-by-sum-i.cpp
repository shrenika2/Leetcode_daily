class Solution {
public:
#define ll long long
    long long sumAndMultiply(int n) {
        string nw = "";
        ll sm = 0 ;
        while (n > 0 ){
            ll lt = n%10;
            n/=10;
            if(lt!=0){
                nw+=to_string(lt);
                sm+=lt;
            }
        }
        reverse(nw.begin(),nw.end());
         if (nw.empty()) return 0;

        return stoi(nw)*sm;
        
    }
};