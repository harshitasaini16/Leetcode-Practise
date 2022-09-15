class RandomizedSet {
public:
    vector<int>v;
    map<int,int>m;
    RandomizedSet() {
        v.clear();
        m.clear();
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            m[val]=v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end()){
            int n=v.size();
            int x=m[val];
            int y=v[n-1];
            m[y]=x;
            swap(v[x],v[n-1]);
            v.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
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