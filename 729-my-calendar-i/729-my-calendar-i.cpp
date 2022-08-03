class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
        v.clear();
    }
    // 47 50
    // 33 41
    // 39 45
    // 33 42
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
            int x=v[i].first;
            int y=v[i].second;
            if(x<start && start<y){
                return false;
            }
            if(x<end && end<y){
                return false;
            }
            if(start<=x && y<=end){
                return false;
            }
        }
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */