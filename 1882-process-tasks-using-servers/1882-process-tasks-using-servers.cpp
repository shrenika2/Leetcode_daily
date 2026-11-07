#define ll long long
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>free;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>busy;
        for(int i=0;i<n;i++) free.push({servers[i],i});
        vector<int>ans;
        ll t=0;
        auto releaseServers=[&](ll time){
            while(!busy.empty() && busy.top().first<=time){
                auto it=busy.top();
                busy.pop();
                free.push({servers[it.second],it.second});
            }
        };
        for(int i=0;i<m;i++){
            t=max(t,1LL*i);
            releaseServers(t);
            if(free.empty()){
              t=busy.top().first;
              releaseServers(t);
            }
            auto it=free.top();
            free.pop();
            ans.push_back(it.second);
            busy.push({t+tasks[i],it.second});
        }      
        return ans;
    }
};