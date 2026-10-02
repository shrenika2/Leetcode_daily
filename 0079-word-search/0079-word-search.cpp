class Solution {
public:
    int dr[4] = {-1 , 0 , 1 , 0};
    int dc[4] = {0 , 1 , 0 , -1};
    int n , m;
    bool find(vector<vector<char>>&board , int i , int j , int idx , string &word){
        if(idx == word.length()){
            return true ;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j]=='$' || board[i][j]!=word[idx] ){
            return false;
        }

        char temp = board[i][j];
        board[i][j]='$';

        for (int k = 0 ; k < 4 ; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(find(board , nr , nc , idx+1 , word)){
                return true ;
            }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         n = board.size();
         m = board[0].size();
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (board[i][j]==word[0] && find(board , i , j , 0 , word))
                {
                    return true ;
                }
            }
        }
        return false;
    }
};