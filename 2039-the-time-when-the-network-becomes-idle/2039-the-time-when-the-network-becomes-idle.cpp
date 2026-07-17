class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);

        for (auto & e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dist(n , -1);
        queue<int> q ;

        dist[0]=0;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for (int ne : adj[node]){
                if(dist[ne]==-1){
                    dist[ne]=dist[node]+1;
                    q.push(ne);
                }
            }
        }
        int ans = 0 ;
        for (int i = 1 ; i < n ; i++){
            int rt = 2 * dist[i];
            int lr ;
            if(rt<=patience[i]){
                lr = rt;
            }else{
                int ls = ((rt-1)/patience[i])*patience[i];
                lr = ls + rt;
            }
            ans = max(ans , lr);
        }
        return ans+1;
    }
};