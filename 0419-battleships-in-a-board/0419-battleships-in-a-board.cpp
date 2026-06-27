class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int dr[4]={-1 , 0 , 1 , 0 };
        int dc[4]={0 , 1 , 0 , -1};
        queue<pair<int ,int>>q;
        int cnt = 0 ;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(board[i][j]=='X'){
                    cnt++;
                    q.push({i , j});
                    while(!q.empty()){
                        auto[r , c]=q.front();q.pop();
                        for (int i = 0 ; i < 4 ; i++){
                            int nr = r + dr[i];
                            int nc = c + dc[i];

                            if(nr >= 0 && nc >= 0 && nr<n && nc<m && board[nr][nc]=='X'){
                                board[nr][nc]='.';
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