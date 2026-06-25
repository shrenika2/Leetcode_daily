class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0 ;
        vector<vector<bool>>vis(n , vector<bool>(m , 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
             
        queue<pair<int,int>> q ;
        q.push({i , j});
        vis[i][j]=1;

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){
            auto[r , c]=q.front();q.pop();
            for (int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>= 0 && nc>= 0 && nr<n && nc < m && vis[nr][nc]!=1 && grid[nr][nc]=='1'){
                    vis[nr][nc]=1;
                    q.push({nr , nc});
                }
            }
        }
           }
            }
        }
        return cnt ;
    }
};