class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int p = 0 ;

        int dr[4]={-1 , 0 , 1 , 0};
        int dc[4]={0 , 1 , 0 , -1};

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    for (int d = 0 ; d < 4 ; d++){
                        int ni = i + dr[d];
                        int nj = j +dc[d];

                        if(ni < 0 || ni >= n || nj < 0 || nj >= m ||grid[ni][nj]==0){
                            p++;
                        }
                    }
                }
            }
        }
return p;

        
    }
};