class Solution {
public:
    string getSmallestString(int n, int k) {
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=1;
            k--;
        }
        int i=n-1;
        while(i>=0 && k>=0){
            if(k>=25){
                a[i]=26;
                k-=25;
            }
            else{
                a[i]=a[i]+k;
                k=0;
            }
            i--;
        }
        string s="";
        for(int i=0;i<n;i++){
            s.push_back(a[i]+'a'-1);
        }
        return s;
    }
};