class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> in(n+1 , 0);
       // vector<int> out(n+1 , 0 );

        for (auto it : edges){
            int u = it[0];
            int v = it[1];

            in[u]++;in[v]++;
            //out[v]++;out[u]++;
        }
        for (int i = 1 ; i<= n ; i++){
            if(in[i]==n-1) return i;
        }
        return -1;
    }
};