class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int>in(n , 0);

        for (auto &it : p){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            in[v]++;
        }

        queue<int> q ;

        for (int i = 0 ; i < n ; i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                in[it]--;

                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==n){
        reverse(topo.begin() , topo.end());
        return topo;
        }else{
            return {};
        }
    }
};