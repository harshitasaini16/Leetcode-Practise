class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        reverse(a.begin(),a.end());
        int c=1;
        for(int i=0;i<a.size();i++){
            int x=a[i]+c;
            a[i]=x%10;
            c=x/10;
        }
        while(c>0){
            a.push_back(c%10);
            c=c/10;
        }
        reverse(a.begin(),a.end());
        return a;
    }
};