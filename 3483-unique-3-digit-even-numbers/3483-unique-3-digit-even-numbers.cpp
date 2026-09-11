class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        bool uniqEven[10] = {false};
        int count = 0;

        for (int d : digits) {
            if (d % 2 == 0) {
                uniqEven[d] = true;
            }
            freq[d]++;
        }

        for (int e = 0; e <= 9; e++) {
            if (!uniqEven[e]) {
                continue;
            }

            freq[e]--;

            vector<int> keys;

            for (int d = 0; d <= 9; d++) {
                if (freq[d] > 0) {
                    keys.push_back(d);
                }
            }

            for (int i = 0; i < keys.size(); i++) {
                for (int j = i + 1; j < keys.size(); j++) {
                    int a = keys[i];
                    int b = keys[j];

                    if (a != 0) {
                        count++;
                    }

                    if (b != 0) {
                        count++;
                    }
                }
            }

            for (int num : keys) {
                if (freq[num] >= 2 && num != 0) {
                    count++;
                }
            }

            freq[e]++;
        }

        return count;
    }
};