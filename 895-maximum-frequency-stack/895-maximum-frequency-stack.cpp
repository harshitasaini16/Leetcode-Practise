class FreqStack {
    priority_queue<vector<int>> pq;
    unordered_map<int, int> m; 
    int count=0; 
    public:
    FreqStack(){ 
    }
    void push(int x){ 
        ++m[x]; 
        pq.push({m[x],count++,x}); 
    }
    int pop(){
        auto maxx = pq.top(); 
        pq.pop(); 
        --m[maxx[2]]; 
        return maxx[2]; 
    }
};