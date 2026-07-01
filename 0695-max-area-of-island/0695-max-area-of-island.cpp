class Solution {
public:
int dfs(int r , int c , vector<vector<int>>& grid , vector<vector<bool>> & vis){
    vis[r][c]=1;
      int dr[4]={-1 , 0 , 1 , 0};
        int dc[4]={0 , 1 , 0 , -1};
        int area = 1 ;int n=grid.size();
    int m=grid[0].size();
    for(int i = 0 ; i < 4 ; i++){
        int nr = r + dr[i];
        int nc= c+dc[i];
       if(nr>=0 && nr<n &&
           nc>=0 && nc<m &&
           !vis[nr][nc] &&
           grid[nr][nc]==1){

            area+=dfs(nr,nc,grid,vis);
        }
    }
    return area;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<bool>>vis(n , vector<bool>(m , 0));
     
int ans = 0 ;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(grid[i][j]==1 && !vis[i][j]){

                ans=max(ans,dfs(i,j,grid,vis));
            }
            }
        }
        return ans ;
    }
};