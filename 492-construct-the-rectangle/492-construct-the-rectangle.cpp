class Solution {
public:
    vector<int> constructRectangle(int area) {
        int x=sqrt(area);
        for(int i=x;i>=1;i--){
            if(area%i==0){
                return {area/i,i};
            }
        }
        return {0,0};
    }
};