class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int , int>> q ;
        int time = 0 ;
        int fresh = 0 ;
        for (int i = 0 ; i < n ; i++){
            for (int j  =0 ; j < m ; j++){
                if(grid[i][j]==2){
                    q.push({i , j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0 ;
        }
        int dr[4]={-1 , 0 , 1 , 0};
        int dc[4]={0 , 1 , 0 , -1};

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
            auto[r , c]=q.front();
            q.pop();

            for (int k = 0 ; k < 4 ; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>= 0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 ){
                    fresh--;
                    grid[nr][nc]=2;
                    q.push({nr , nc});
                }
                
            }
           
            }
            if(!q.empty()){
                time++;
            }
            
        }
        return fresh==0 ? time:-1 ;
    }
};