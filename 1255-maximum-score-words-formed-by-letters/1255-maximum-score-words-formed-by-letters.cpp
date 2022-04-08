class Solution {
public:
    bool isvalid(string word,map<char,int>av){
        for(int i=0;i<word.length();i++){
            if(av[word[i]]==0){
                return false;
            }
            av[word[i]]--;
        }
        return true;
    }
    int fun(int x,vector<string>& words,map<int,int>sc,map<char,int>av){
        if(x>=words.size()){
            return 0;
        }
        int ans=fun(x+1,words,sc,av);
        if(isvalid(words[x],av)){
            int s=0;
            for(int i=0;i<words[x].length();i++){
                s+=sc[words[x][i]-'a'];
                av[words[x][i]]--;
            }
            ans=max(ans,s+fun(x+1,words,sc,av));
        }
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<int,int>sc;
        map<char,int>av;
        for(int i=0;i<letters.size();i++){
            av[letters[i]]++;
        }
        for(int i=0;i<score.size();i++){
            sc[i]=score[i];
        }
        return fun(0,words,sc,av);
    }
};