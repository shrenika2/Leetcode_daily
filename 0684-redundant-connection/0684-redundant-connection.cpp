class DSU{
public: 
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1 , 0);

        for (int i  =1 ; i <= n ; i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(x==parent[x]){
            return x ;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x , int y){
        int xp = find(x);
        int yp = find(y);
        if(xp!= yp){
            if(rank[xp]>rank[yp]){
                parent[yp]=xp;
            }else if(rank[xp]<rank[yp]){
                parent[xp]=yp;
            }else{
                parent[xp]=yp;
                rank[yp]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto & it : edges){
            int u = it[0];
            int v = it[1];

            if(dsu.find(u)==dsu.find(v)){
                return it;
            }
            dsu.Union(u , v);
        }
        return {};
    }
};