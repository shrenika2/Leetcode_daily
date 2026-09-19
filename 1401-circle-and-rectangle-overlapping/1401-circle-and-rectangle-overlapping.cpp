class Solution {
public:
    bool checkOverlap(int radius,int xc,int yc,int x1,int y1,int x2,int y2){
        int xp,yp;
        xp=max(x1,min(xc,x2));
        yp=max(y1,min(yc,y2));

        return radius*radius>=pow(xp-xc,2)+pow(yp-yc,2);
    }
};