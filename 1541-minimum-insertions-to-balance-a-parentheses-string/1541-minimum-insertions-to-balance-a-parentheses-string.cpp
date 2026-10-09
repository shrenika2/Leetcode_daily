  
class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                if (cnt % 2 == 1) {
                    cnt--;
                    ans++;
                }
                cnt += 2;
            } else {
                cnt--;

                if (cnt < 0) {
                    ans++;
                    cnt = 1;
                }
            }
        }

        return ans + cnt;
    }
};
