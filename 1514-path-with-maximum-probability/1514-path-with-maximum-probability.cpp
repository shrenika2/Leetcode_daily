class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){

            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n , 0.0);
        pq.push({1.0 , start_node});
        dist[start_node]=1.0;
        while(!pq.empty()){
            auto [succ , node]=pq.top();
            pq.pop();
            if(succ < dist[node]) continue ;
            if(node == end_node) return succ;
            for(auto [neigh ,s]: adj[node]){
                
            double newProb = succ * s;
            if(newProb > dist[neigh]){
            dist[neigh] = newProb;

            pq.push({newProb, neigh});
}
            }
        }
        return 0.0 ;
    }
};