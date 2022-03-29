class Bitset {
public:
    // int zero;
    // int one;
    int n;
    // map<int,int>z;
    map<int,int>o;
    bool f=true;
    Bitset(int size) {
        n=size;
        // z.clear();
        o.clear();
    }
    
    void fix(int idx) {
        if(f==true){
            if(o.find(idx)==o.end()){
                o[idx]++;
            }
        }
        else if(f==false){
            if(o.find(idx)!=o.end()){
                o.erase(idx);
            }
        }
    }
    
    void unfix(int idx) {
         if(f==true){
            if(o.find(idx)!=o.end()){
                o.erase(idx);
            }
        }
        else if(f==false){
            if(o.find(idx)==o.end()){
                o[idx]++;
            }
        }
    }
    
    void flip() {
        if(f==true){
            f=false;
        }
        else{
            f=true;
        }
    }
    
    bool all() {
        if(f==true){
            if(o.size()==n){
                return true;
            }
            return false;
        }
        else{
            if(o.size()==0){
                return true;
            }
            return false;
        }
    }
    
    bool one() {
        if(f==true){
            if(o.size()>0){
                return true;
            }
            return false;
        }
        else{
            if(o.size()<n){
                return true;
            }
            return false;
        }
    }
    
    int count() {
        if(f==true){
            return o.size();
        }
        else{
            return n-o.size();
        }
    }
    
    string toString() {
        string s="";
        if(f==true){
            for(int i=0;i<n;i++){
                if(o.find(i)!=o.end()){
                    s.push_back('1');
                }
                else{
                    s.push_back('0');
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(o.find(i)==o.end()){
                    s.push_back('1');
                }
                else{
                    s.push_back('0');
                }
            }
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */