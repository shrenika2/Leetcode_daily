class Solution {
public:

    bool check(int a, int b, int c, int d) {
        return c < b && d > a;
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    
        bool xOverlap = check(rec1[0], rec1[2], rec2[0], rec2[2]);

        bool yOverlap = check(rec1[1], rec1[3], rec2[1], rec2[3]);

        return xOverlap && yOverlap;
    }
};