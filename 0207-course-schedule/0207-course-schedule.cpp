class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for(auto it : p){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            in[v]++;
        }
        queue<int>q;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(in[i]==0){
                q.push(i);
            }
            }while(!q.empty()){
                    auto node = q.front();
                    q.pop();
                   cnt++;
                    
                for (auto itt: adj[node]){
                    in[itt]--;
                    if(in[itt]==0) {
                        q.push(itt);
                    }
                }
            
        }
        return cnt == n ? true : false;

    }
};