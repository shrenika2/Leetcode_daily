class Solution {
public:
int mx = 0 ;
int cnt = 0;


    void dfs(int r , int c , vector<vector<int>>& grid ){
         int dr[4]={0 , -1 , 0 , 1};
        int dc[4]={-1 , 0 , 1 , 0};
      
         int n = grid.size();
        int m = grid[0].size();
       
        for (int k = 0 ; k < 4 ; k++){
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if(nr < n && nc < m && nr>=0 && nc >= 0 && grid[nr][nc]==1){
                            cnt++;
                            grid[nr][nc]=0;
                            dfs(nr , nc , grid);
                        }
                    }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
      
        vector<vector<bool>> vis(n , vector<bool>(m , 0));
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                   cnt = 1;
                    grid[i][j] = 0;
                    dfs(i, j, grid);
                    mx = max(mx, cnt);
            }
        }
        }
        return mx ;
        
    }
};