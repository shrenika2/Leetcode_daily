class Solution {
public:
long root_result = 0 ;
vector<int> cnt;
int N ;

    void dfsbase(unordered_map<int, vector<int>>& adj, int curr_node, int prev_node, int curr_depth){
        cnt[curr_node]=1;
        root_result+=curr_depth;

        for (int &child : adj[curr_node]){
            if(child == prev_node) continue ;

            dfsbase(adj , child , curr_node , curr_depth+1);
            cnt[curr_node]+=cnt[child];
        }
    }

    void dfsResult(unordered_map<int, vector<int>>& adj, int parent_node, int prev_node, vector<int>& result){
        for(int &child : adj[parent_node]){
            if(child == prev_node) continue ;

            result[child]=result[parent_node] - cnt[child] + (N - cnt[child]);
            
            dfsResult(adj , child , parent_node , result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        unordered_map<int , vector<int>> adj;

        for (auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cnt.resize(n , 0);
        vector<int> result (n , 0);

        dfsbase(adj, 0 , -1 , 0 );
        result[0]=root_result;

        dfsResult(adj , 0 , -1 , result);

        return result ;
    }
};