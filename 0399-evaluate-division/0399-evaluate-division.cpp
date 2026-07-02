class Solution {
public:

    void dfs(unordered_map<string , vector<pair <string , double>>> &adj , string src , string des , unordered_set<string> &vis , double& pro , double& ans){
        if(vis.find(src) != vis.end()){
            return ;
        }
        vis.insert(src);

        if(src == des){
            ans = pro ;
            return ;
        }

        for (auto& it : adj[src]){
            string v = it.first;
            double val = it.second;

             if(!vis.count(v))
        {
            pro *= val;

            dfs(adj, v, des, vis, pro, ans);

            pro /= val;

            if(ans != -1.0)
                return;
        }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , vector<pair <string , double>>> adj;

        int n = equations.size();
        int m = queries.size();

        for (int i = 0 ; i < n ; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v , val});
            adj[v].push_back({u , 1.0/val});
        }

        vector<double> result;

        for (int i = 0 ; i < m ; i++){
            string src = queries[i][0];
            string des = queries[i][1];

            if(adj.find(src)==adj.end()||adj.find(des)==adj.end()){
                result.push_back(-1.0);
            }else{
                double ans = -1.0;
                double pro = 1.0;
                unordered_set<string> vis;

                dfs(adj , src , des , vis , pro , ans);
                result.push_back(ans);
            }
        }
        return result;
    }
};