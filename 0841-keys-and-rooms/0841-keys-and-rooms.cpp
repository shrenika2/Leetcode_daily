class Solution {
public:

void dfs(int n , vector<vector<int>>& rooms ,vector<bool>&vis ){
    vis[n]=true;
    for (auto it : rooms[n]){
        if(!vis[it]){
        dfs(it , rooms , vis);}
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n , false);
        dfs(0 , rooms , vis);

        for (int i = 0 ; i < n ; i++){
            if(vis[i]==false){
                return false ;
            }
        }
        return true ;
    }
};