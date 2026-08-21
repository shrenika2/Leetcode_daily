class Solution {
public:
    bool dfs(vector<vector<int>>& edges , vector<bool> &vis , int s , int d){
        if(s ==d) return true;
        vis[s]= true;
        for (auto it : edges[s]){
            if(!vis[it]){
            if (dfs(edges, vis, it, d))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      //  int n = edges.size();
      vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n , false);
        bool ans = dfs(adj, vis, source, destination);
        return ans ;
    }
};