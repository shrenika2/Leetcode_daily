class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        for (int len = k; len <= n; len++) {
            string ans = "";

            for (int i = 0; i + len <= n; i++) {
                string t = s.substr(i, len);

                int cnt = 0;
                for (char c : t) {
                    if (c == '1') cnt++;
                }

                if (cnt == k && (ans == "" || t < ans))
                    ans = t;
            }

            if (ans != "")
                return ans;
        }

        return "";
    }
};