class Solution {
public:
int ans = INT_MAX;
    void dfs(int node , vector<vector<pair<int , int>>> &adj ,vector<bool> &vis ){
        vis[node]=true;

        for (auto &it : adj[node]){
            int u = it.first;
            int v = it.second;

            ans = min(ans , v);

            if(!vis[u]){
                dfs(u , adj , vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
       
        vector<vector<pair<int , int>>> adj(n+1);

        for (auto &e :roads ){
            adj[e[0]].push_back({e[1] , e[2]});
            adj[e[1]].push_back({e[0] , e[2]});
        }
        vector<bool> vis(n+1 , false);
        dfs(1 , adj , vis);
        return ans ;
    }
};