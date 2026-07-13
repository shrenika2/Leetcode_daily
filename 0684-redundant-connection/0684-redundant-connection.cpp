class Solution {
public:
    bool dfs(int u , int v , unordered_map<int , vector<int>> & adj , vector<bool>&vis){
        vis[u]=true ;

        if(u == v) return true ;

        for (auto it : adj[u]){
            if(!vis[it]){
                if(dfs(it , v , adj , vis)){
                    return true ;
                }
            }
        }
        return false ;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int , vector<int>> adj ;

        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            vector<bool> vis(n+1 , false);
            if(adj.count(u) && adj.count(v) && dfs(u , v , adj , vis) ){
                return it;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};