class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        int step = 0 ;
        set<string> st(deadends.begin() , deadends.end()) ;
         if (st.count("0000")) return -1;
        if (target == "0000") return 0;
        queue<string>q;
        set<string> vis;
        q.push("0000");
        vis.insert("0000");
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                if (curr == target) return step;
                for (int i = 0 ; i < 4 ; i++){
                    string nt = curr;

                    nt[i]=(curr[i]-'0' + 1) % 10 + '0';

                    if(!st.count(nt) && !vis.count(nt)){
                        vis.insert(nt);
                        q.push(nt);
                    }  
                    nt = curr;
                    nt[i] = (curr[i] - '0' + 9) % 10 + '0';

                    if (!st.count(nt) && !vis.count(nt)) {
                        vis.insert(nt);
                        q.push(nt);
                    }           
                }
            }
            step++;
        }

        return -1 ;
    }
};