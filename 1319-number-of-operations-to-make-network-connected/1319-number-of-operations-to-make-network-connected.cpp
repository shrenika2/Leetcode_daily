class Solution {
public:

    int find(int i , vector<int> &parent){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i] , parent);
    }

    void Union(int x , int y , vector<int> &parent , vector<int> rank){
        int rx = find(x , parent);
        int ry = find(y , parent);

        if(rx!=ry){
            if(rank[rx]>rank[ry]){
                parent[ry]=rx;
            }else if(rank[rx]<rank[ry]){
                parent[rx]=ry;
            }else{
                parent[ry]=rx;
                rank[rx]++;
        }
    }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1 ;
        }

        vector<int> parent(n);
        vector<int> rank(n , 0);

        iota(parent.begin() , parent.end() , 0);

        int comp = n ;

        for (auto &it : connections){
            int u = it[0];
            int v = it[1];

            int ru = find(u , parent);
            int rv = find(v , parent);

            if(ru != rv){
                Union(u , v , parent , rank);
                comp--;
            }
        }
        return comp -1 ;
    }
};