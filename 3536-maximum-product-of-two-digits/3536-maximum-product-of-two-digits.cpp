class Solution {
public:
    int maxProduct(int n) {
        
        string s = to_string(n);
        int sz = s.size();
        if(sz==1) return n;
        sort(s.begin() , s.end());
        int a = s[sz-2]-'0';
        int b = s[sz-1]-'0';
        return (a * b);
        
    }
};