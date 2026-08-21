class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n);
        vector<int> in(n +1, 0);
        vector<int> out(n +1, 0);

        for (auto it : trust){
            int u = it[0];
            int v = it[1];
            //adj[v].push_back(u);
            out[u]++;in[v]++;
            
        }
        for (int i = 1 ; i <= n ; i++){
            if(in[i]==n-1 && out[i]==0) return i;
        }
        return -1 ;
    }
};