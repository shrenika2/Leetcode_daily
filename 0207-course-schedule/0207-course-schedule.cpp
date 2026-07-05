class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> in(n , 0);
        for(auto &it : p){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            in[v]++;
        }
        queue<int>q;
        for (int i = 0 ; i < n ; i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int cnt = 0 ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for (auto nei : adj[node]){
                in[nei]--;

                if(in[nei]==0){
                    q.push(nei);
                }
            }
        }

            return cnt== n;
        }
};