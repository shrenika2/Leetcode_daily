class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int cnt1 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                cnt1++;
        }

        int cnt2 = 0;
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                cnt2++;
        }

        int sm = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] != '?')
                sm += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] != '?')
                sm -= num[i] - '0';
        }

        if ((cnt1 - cnt2) % 2 != 0)
    return true;

return sm != -9 * (cnt1 - cnt2) / 2;
    }
};