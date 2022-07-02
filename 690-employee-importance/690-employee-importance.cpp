/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> em, int id) {
        queue<int>q;
        q.push(id);
        int ans=0;
        map<int,int>imp;
        map<int,vector<int>>emp;
        for(int i=0;i<em.size();i++){
            imp[em[i]->id]=em[i]->importance;
            emp[em[i]->id]=em[i]->subordinates;
        }
        while(!q.empty()){
            int x=q.front();
            ans+=imp[x];
            vector<int>v=emp[x];
            q.pop();
            for(int i=0;i<v.size();i++){
                q.push(v[i]);
            }
        }
        return ans;
    }
};