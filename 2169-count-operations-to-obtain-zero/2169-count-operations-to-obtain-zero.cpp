class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1==0 || num2==0){
            return 0;
        }
        priority_queue<int>q;
        q.push(num1);
        q.push(num2);
        int s=1;
        while(true){
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            if(x==y){
                return s;
            }
            q.push(y);
            q.push(x-y);
            s++;
        }
    }
};