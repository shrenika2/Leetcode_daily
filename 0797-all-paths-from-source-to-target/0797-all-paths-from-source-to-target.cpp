class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int node, vector<vector<int>>& graph, vector<int>& path) {
        path.push_back(node);

        if (node == graph.size()-1) {
            ans.push_back(path);
        } else {
            for (int ne : graph[node]) {
                dfs(ne, graph, path);
            }
        }
         path.pop_back(); 
       
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<int> path;
        dfs(0, g, path); 
        return ans;
    }
};