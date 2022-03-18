class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v;
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                int x=0;
                for(int k=i;k<=j;k++){
                    x=(x*10)+k;
                }
                if(x>=low && x<=high){
                    v.push_back(x);
                }
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};