class RandomizedSet {
public:
    map<int,int>m;
    RandomizedSet() {
        m.clear();
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()){
            return false;
        }
        else{
            m[val]++;
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end()){
            m.erase(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
       vector<int>v;
        for(auto i:m){
            v.push_back(i.first);
        }
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */