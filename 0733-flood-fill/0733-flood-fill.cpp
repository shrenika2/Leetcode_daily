class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& images, int sr, int sc, int color) {
        int n = images.size();
        int m = images[0].size();
        int inicolor = images[sr][sc];
         if (inicolor == color) return images;
        images[sr][sc]=color;
        vector<vector<int>> vis(n , vector<int>(m , 0));
        queue<pair<int , int>> q;
        q.push({sr , sc});
        vis[sr][sc]=1;

        int dr[4]={-1 , 0 , 1 , 0};
        int dc[4]={0 , 1 , 0 , -1};
        while(!q.empty()){
            auto[r , c] = q.front();
            q.pop();

            for (int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr<n && nr>=0 && nc < m && nc>=0 && vis[nr][nc]!=1 && images[nr][nc]!=color && images[nr][nc]==inicolor){
                    images[nr][nc]=color;
                    vis[nr][nc]=1;
                    q.push({nr , nc});
                }
            }


        }
return images;



    }
};