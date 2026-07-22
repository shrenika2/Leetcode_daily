class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m =  h[0].size();
        
        vector<vector<int>> dist(n , vector<int>(m ,INT_MAX));
        priority_queue<vector< int> , vector<vector< int>> , greater<vector<int>>> pq;
        pq.push({0 , 0 , 0});
        dist[0][0]=0;
        int dr[4]={-1 , 0 , 1 , 0};
        int dc[4]={0 , 1 , 0 , -1};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int eff = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(r==n-1 && c==m-1)
                return eff;

            if(eff > dist[r][c]) continue;

            for (int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int currdiff = abs(h[nr][nc]-h[r][c]);
                    int nweff = max(eff , currdiff);

                    if(nweff < dist[nr][nc]){
                        dist[nr][nc]=nweff;
                        pq.push({nweff , nr , nc});
                    }
                }
            }
        }
        return 0 ;
    }
};