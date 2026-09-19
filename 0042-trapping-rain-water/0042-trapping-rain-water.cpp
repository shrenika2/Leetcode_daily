class Solution {
public:
    int trap(vector<int>& h) {
        int s = 0 ;
        int e = h.size()-1;

        int lmx = 0 ;
        int rmx = 0 ;
        int t = 0 ;

        while(s < e){
            lmx = max(lmx , h[s]);
            rmx = max(rmx , h[e]);

            if(lmx < rmx ){
                t += lmx - h[s];
                s++;
            }else{
                t+=rmx - h[e];
                e--;
            }
        }
        return t;
    }
};