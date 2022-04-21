class MyHashSet {
public:
    vector<int>v;
    MyHashSet() {
      for(int i=0;i<=1000001;i++){
          v.push_back(-1);
      }
    }
    
    void add(int key) {
       v[key]=1;
    }
    
    void remove(int key) {
       v[key]=-1;
    }
    
    bool contains(int key) {
        if(v[key]==-1){
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */