class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis, int &nodes, int &degSum) {
        vis[u] = 1;
        nodes++;
        degSum += adj[u].size();

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis, nodes, degSum);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n , 0);
        int ans = 0 ;

        for (int i=0 ; i < n; i++){
            if(!vis[i]){
                int nodes = 0 , degsum = 0 ;
                dfs(i , adj , vis , nodes , degsum);

                int ec = degsum/2;
                if(ec==nodes*(nodes-1)/2){
                    ans++;
                }
            }
        }
        return ans ;
    }
};