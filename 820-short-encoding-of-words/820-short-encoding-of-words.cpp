class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
        }
        sort(words.begin(),words.end());
        int n=words.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(words[i].length()<=words[i+1].length()){
                string a=words[i];
                string b=words[i+1].substr(0,words[i].length());
                if(a!=b){
                    ans+=words[i].length()+1;
                }
            }
            else{
                ans+=words[i].length()+1;
            }
        }
        ans+=words[n-1].length()+1;
        return ans;
    }
};
