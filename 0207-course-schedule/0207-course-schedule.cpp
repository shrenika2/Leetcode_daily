class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses);
        for (auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            in[v]++;
        }
        queue<int> q;
        int cnt = 0 ;
        for (int i = 0 ; i < numCourses ; i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            cnt++;

            for (auto itt : adj[node]){
                in[itt]--;
                if(in[itt]==0){
                    q.push(itt);
                }
            }
        }
        return cnt == numCourses ? true : false;
        
    }
};