class UndergroundSystem {
public:
    map<int,pair<int,string>>in;
    map<pair<string,string>,int>m;
    map<pair<string,string>,int>c;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]={t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        m[{in[id].second,stationName}]+=t-in[id].first;
        c[{in[id].second,stationName}]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        int x=m[{startStation,endStation}];
        int y=c[{startStation,endStation}];
        return (double)x/(double)y;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */