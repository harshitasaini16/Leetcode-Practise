class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        vector<int>v(n,1);
        if(n==1){
            return 1;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(rating[i]>rating[i+1]){
                    v[i]=1+v[i+1];
                }
            }
            else if(i==n-1){
                if(rating[i]>rating[i-1]){
                    v[i]=1+v[i-1];
                }
            }
            else{
                if(rating[i]>rating[i-1] && rating[i]>rating[i+1]){
                    v[i]=1+max(v[i-1],v[i+1]);
                }
                else if(rating[i]>rating[i-1]){
                    v[i]=v[i-1]+1;
                }
                else if(rating[i]>rating[i+1]){
                    v[i]=v[i+1]+1;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==0){
                if(rating[i]>rating[i+1]){
                    v[i]=1+v[i+1];
                }
            }
            else if(i==n-1){
                if(rating[i]>rating[i-1]){
                    v[i]=1+v[i-1];
                }
            }
            else{
                if(rating[i]>rating[i-1] && rating[i]>rating[i+1]){
                    v[i]=1+max(v[i-1],v[i+1]);
                }
                else if(rating[i]>rating[i-1]){
                    v[i]=v[i-1]+1;
                }
                else if(rating[i]>rating[i+1]){
                    v[i]=v[i+1]+1;
                }
            }
        }
        int s=0;
        for(int i=0;i<v.size();i++){
            s+=v[i];
        }
        return s;
    }
};    