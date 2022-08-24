class LRUCache {
public:
    struct node{
        int key;
        int value;
        node* prev;
        node* next;
        node(int k,int v){
            key=k;
            value=v;
        }
    };
    int cap;
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    map<int,node*>m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        m.clear();
    }
    void add(node *nn){
        node *f=head->next;
        head->next=nn;
        nn->next=f;
        f->prev=nn;
        nn->prev=head;
    }
    void del(node *nn){
        node *prv=nn->prev;
        node *nxt=nn->next;
        prv->next=nxt;
        nxt->prev=prv;
    }
    int get(int key) {
       if(m.find(key)!=m.end()){
           node *n=m[key];
           node *nn=new node(key,n->value);
           del(n);
           add(nn);
           m[key]=nn;
           return nn->value;
       }
       return -1;
    }
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *n=m[key];
            del(n);
            m.erase(key);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            del(tail->prev);
        }
        node *nn=new node(key,value);
        add(nn);
        m[key]=nn;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */