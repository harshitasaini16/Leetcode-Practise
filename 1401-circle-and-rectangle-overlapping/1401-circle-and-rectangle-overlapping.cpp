class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                int x=sqrt(abs(xc-i)*abs(xc-i)+abs(yc-j)*abs(yc-j));
                if(x<=radius){
                    return true;
                }
            }
        }
        return false;
    }
};