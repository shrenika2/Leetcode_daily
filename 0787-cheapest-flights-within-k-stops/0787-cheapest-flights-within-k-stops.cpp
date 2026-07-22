class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);

    for (auto &it :flights ){
        adj[it[0]].push_back({it[1] , it[2]});
    }

    vector<int> dist(n , INT_MAX);
    queue<vector<int>> q;

    q.push({0 , src , 0});
    dist[src]=0;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int stops = cur[0];
        int node = cur[1];
        int cost = cur[2];

        if(stops > k) continue;

        for (auto&[nei , wt]: adj[node]){
            if(cost + wt < dist[nei]){
                dist[nei]=cost+wt;
                q.push({stops+1 , nei , dist[nei]});
            }
        }
    }
    return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};