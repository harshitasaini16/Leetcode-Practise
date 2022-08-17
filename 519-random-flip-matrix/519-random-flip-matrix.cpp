class Solution {
public:
    map<pair<int,int>,int>mp;
    int n;
    int m;
    Solution(int a, int b) {
        mp.clear();
        n=a;
        m=b;
    }
    
    vector<int> flip() {
        if(mp.size()==n*m){
            return {};
        }
        while(true){
            int x = (rand() % n);
            int y = (rand() % m);
            if(mp.find({x,y})==mp.end()){
                mp[{x,y}]++;
                return {x,y};
            }
        }
        return {};
    }
    
    void reset() {
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */