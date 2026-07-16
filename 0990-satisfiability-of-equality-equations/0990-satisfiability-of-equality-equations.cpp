class Solution {
public:
    class DSU {
    public: 
        vector<int> parent;
        DSU(){
            parent.resize(26);
            for (int i = 0 ; i < 26 ; i++){
                parent[i]=i;
            }
        }
        int find(int x){
            if(parent[x]==x){
                return x;
            }
            return parent[x]=find(parent[x]);
        }
        void unite(int a , int b){
            a = find(a);
            b = find(b);

            if(a!=b){
                parent[b]=a;
            }
        }
    };

    bool equationsPossible(vector<string>& equations) {
        DSU dsu ;
        for (auto it :equations ){
            if(it[1]=='='){
                int u = it[0]-'a';
                int v = it[3]-'a';
                dsu.unite(u , v);
            }
        }
        for (auto it : equations){
            if(it[1]=='!'){
                int u = it[0]-'a';
                int v = it[3]-'a';

                if(dsu.find(u)==dsu.find(v))
                return false ;
            }
        }
        return true ;
    }
};