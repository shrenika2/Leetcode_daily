class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n , vector<int>(m , -1));
        queue<pair < int , int>> q ;
        int land = 0 ;

        for (int i = 0 ; i < n;i++){
            for (int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    land++;
                    q.push({i , j});
                    dist[i][j]=0;
                }
            }
        }
        if(land==0 || land==n*m){
            return -1 ;
        }
        int dr[4]={-1 , 0 , 1 , 0};
        int dc[4]={0 , 1 , 0 , -1};

        while(!q.empty()){
           
                auto[r , c]=q.front();
                q.pop();

                for (int k = 0 ; k < 4 ; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr>= 0 && nc >= 0 && nr<n && nc<m && dist[nr][nc]==-1){
                        dist[nr][nc]=dist[r][c]+1;
                        q.push({nr , nc});
                    }
                }
            
        }
        int mx = 0 ;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                mx = max(mx , dist[i][j]);
            }
        }
        return mx ;
    }
};