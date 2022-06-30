class RandomizedSet {
public:
    map<int,int>m;
    vector<int>v;
    RandomizedSet() {
        m.clear();
        v.clear();
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
            int y=n-1;
            int vv=v[n-1];
            m[vv]=x;
            swap(v[x],v[y]);
            v.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int x=(rand())%v.size();
        return v[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */