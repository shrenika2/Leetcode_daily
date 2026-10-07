class Solution {
public:

    vector<string> ans;

    void dfs(string& s , int i , int lrem , int rrem , int bal , string &path){
       
            if(i==s.size()){
                if(lrem == 0 && rrem == 0 &&  bal == 0){
                    ans.push_back(path);
                }
                return ;
            }
            char c = s[i];

            if(c=='('){
                if(lrem > 0){
                    dfs(s , i+1 , lrem - 1 , rrem , bal , path);
                }
                path.push_back(c);

                dfs(s , i+1 , lrem , rrem , bal+1 , path);
                path.pop_back();
            }
            else if(c==')'){
                if(rrem > 0){
                    dfs(s , i+1 , lrem , rrem - 1 , bal , path);
                }
                if(bal > 0){
                    path.push_back(c);

                    dfs(s , i+1 , lrem , rrem , bal -1 , path);

                    path.pop_back();
                }
            }
            else {
                path.push_back(c);
                dfs(s , i+1 , lrem , rrem , bal , path);

                path.pop_back();
            }
        }
    
    vector<string> removeInvalidParentheses(string s) {
        int lrem = 0 ;
        int rrem = 0 ;

        for(char c : s){
            if(c=='('){
                lrem++;
            }
            else if(c==')'){
                if(lrem>0){
                    lrem--;
                }else{
                    rrem++;
                }
            }
        }
            string path ;
            dfs(s , 0 , lrem , rrem , 0 , path);

            sort(ans.begin() , ans.end());
            ans.erase(unique(ans.begin() , ans.end()) , ans.end());
            return ans ;
        
        
    }
};