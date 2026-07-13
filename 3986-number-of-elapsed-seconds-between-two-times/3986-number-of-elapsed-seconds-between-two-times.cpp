class Solution {
public:
 int convert(string t) {
        int h = (t[0]-'0')*10 + (t[1]-'0');
        int m = (t[3]-'0')*10 + (t[4]-'0');
        int s = (t[6]-'0')*10 + (t[7]-'0');

        return h*3600 + m*60 + s;
    }
    int secondsBetweenTimes(string st, string ed) {
        return convert(ed) - convert(st);
    }
};

