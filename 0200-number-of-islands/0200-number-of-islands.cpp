class Solution {
public:

    void dfs(int r , int c , vector<vector<char>>& grid, vector<vector<bool>> &vis){
         int n = grid.size();
        int m = grid[0].size();
        vis[r][c]=true;
        int dr[4]={-1 , 0 , 1 , 0};
        int dc[4]={0 , 1 , 0 , -1};
        for (int k = 0 ; k < 4 ; k++){
                    int nr = r + dr[k];
                    int nc = c+ dc[k];

                    if(nr<n && nc<m && nr >= 0 && nc >= 0 && !vis[nr][nc] && grid[nr][nc]=='1'){
                        dfs(nr , nc , grid , vis);
                    }

    }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m , false));
        int cnt = 0 ;
       
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(vis[i][j]!=true && grid[i][j]=='1'){
                    cnt++;
                    dfs(i , j , grid , vis);
                }
            }
        }
        return cnt ;
    }
};