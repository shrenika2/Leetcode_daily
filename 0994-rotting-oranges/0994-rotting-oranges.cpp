class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int f = 0 ;
        // vector<vector<int>> vis(n , vector<int>(m , 0));
         int dr[4]={-1 , 0 , 1 , 0};
         int dc[4]={0 , 1 , 0 , -1};
        for (int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(grid[i][j]==2){
                   
                    q.push({{i , j} , 0});
                }else if(grid[i][j] == 1){
                    f++;
                }
            }}
            int t = 0 ;
                    while(!q.empty()){
                        auto curr = q.front();
                        q.pop();

                        int r = curr.first.first;
                        int c = curr.first.second;
                        int ti = curr.second;

                        t = max(t , ti);
                        for(int k = 0 ; k <4 ;k++){
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]==1){
                                grid[nr][nc]=2;
                                f--;
                                q.push({{nr , nc} , ti+1});
                            }
                        }
                    }

                    if(f>0){
                        return -1 ;
                    }
        
        return t ;
    }
};