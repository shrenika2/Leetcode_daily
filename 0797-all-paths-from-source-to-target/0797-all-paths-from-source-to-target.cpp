class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int node ,vector<vector<int>>& graph , vector<int> path ){
        int n = graph.size();
        path.push_back(node);
       
        
        if(node==n-1){
            ans.push_back(path);
            
        }else{
            for(auto it : graph[node]){
                
                
                 dfs(it , graph , path);
            }
        }
       
        
        path.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> path;
       
        dfs(0 , graph , path);
        
        return ans;
    }
};