class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int> in(n , 0);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            in[u]++;
            in[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            
        }
        if(n==1) return {0};
        queue<int> q ;
        for (int i =0 ; i < n ; i++){
            if(in[i]==1)
                q.push(i);
        }
        vector<int> ans ;
        while(n>2){
            int sz = q.size();
            n -=sz;
            while(sz--){
                int node = q.front();
                q.pop();
                
              
                for (auto it : adj[node]){
                    in[it]--;
                    if(in[it]==1)
                        q.push(it);
                }
            }
        }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
    }
    return ans;
    }
};