class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        for(int i=0;i<=cheeseSlices;i++){
            int x=i;
            int y=cheeseSlices-i;
            if(((x*4)+(y*2))==tomatoSlices){
                return {x,y};
            }
        }
        return {};
    }
};