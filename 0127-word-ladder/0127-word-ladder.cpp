class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        set<string> st(wordList.begin() , wordList.end());

        queue<string> q ;
        q.push(beginWord);
        int step = 1 ;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();

                if(curr==endWord) return step;

                for (int i = 0 ; i < curr.size() ; i++){
                    char ori = curr[i];

                    for (char ch = 'a' ; ch<='z' ; ch++){
                        curr[i]=ch;

                        if(st.count(curr)){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i]=ori;
                }
            }
            step++;
        }
        return 0 ;
    }
};