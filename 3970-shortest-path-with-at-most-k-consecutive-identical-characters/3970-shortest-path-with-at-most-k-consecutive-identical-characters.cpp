#define ll long long 
#define vi vector<int>
#define vii vector<vector<int>>
#define viip vector<vector<pair<int , int>>>

struct State{
    int dist ;
    int u ;
    int con;

    bool operator<(const State& other)const{
        return dist > other.dist;
    }
};
// your code goes to here .................
class Solution {
public:
    int shortestPath(int n, vii& e, string lb, int k) {
        viip adj(n);
        for(auto& it : e){
        adj[it[0]].push_back({it[1] , it[2]});}
        int inf = 1e9 + 7;
        int s = k+1;
        vi dist(n*s , inf);
        priority_queue<State>pq;
        dist[0*s+1]=0;
        pq.push({0 ,0,1 });
        while(!pq.empty()){
        State curr = pq.top(); pq.pop();
        int d=curr.dist;int u = curr.u;int c = curr.con;
        if(d>dist[u*s+c]){
        continue;}
        if(u==n-1){
        return d;}
        for (auto it : adj[u]){
        int v = it.first;
        int w = it.second;
        if(lb[v]==lb[u]){
        if(c+1<=k){
        int ni = v*s + (c+1);
        if(d+w < dist[ni]){
     dist[ni]=d+w;
        pq.push({dist[ni] , v , c+1});
        }}}else{
                int ni = v*s+1;
                if(d+w < dist[ni]){
                    dist[ni]=d+w;
         pq.push({dist[ni] , v , 1});
        }}}}       
        return -1;
    }
};