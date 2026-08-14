class Solution {
public:
    int maximumLengthSubstring(string s) {
        int lft = 0, ovr = 0;
        int cnt[128] = {};

        for (char c : s) {
            int oc = (int)c;
            cnt[oc]++;
            ovr += cnt[oc] > 2;

            if (ovr) {
                int ol = (int)s[lft];
                ovr -= cnt[ol] > 2;
                cnt[ol]--;
                lft++;
            }
        }

        return s.size() - lft;
    }
};