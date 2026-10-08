class Solution {
public:
    string removeOuterParentheses(string s) {
    string sa = "";
    int dept = 0 ;
    for (auto it : s){
        if (it == '('){
            if (dept > 0) sa += it;
            dept++;
        } 
        else{
            dept--;
            if (dept > 0) sa += it;
        }
    }
    return sa;
        
    }
};