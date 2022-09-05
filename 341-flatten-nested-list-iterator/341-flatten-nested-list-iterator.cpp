/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger>s;
    NestedIterator(vector<NestedInteger> &v) {
        for(int i=v.size()-1;i>=0;i--){
            s.push(v[i]);
        }
    }
    
    int next() {
        int x=s.top().getInteger();
        s.pop();
        return x;
    }
    
    bool hasNext() {
        while(!s.empty()){
            auto curr=s.top();
            if(curr.isInteger()){
                return true;
            }
            s.pop();
            vector<NestedInteger>b=curr.getList();
            for(int i=b.size()-1;i>=0;i--){
                s.push(b[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */