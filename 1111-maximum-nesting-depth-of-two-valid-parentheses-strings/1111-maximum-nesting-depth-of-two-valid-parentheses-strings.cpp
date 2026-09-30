class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> a;
        int cg = 1;

        for (char b : seq) {
            if (b == '(') {
                a.push_back(1 - cg);
            } else {
                a.push_back(cg);
            }

            cg ^= 1;
        }

        return a;
    }
};