// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        map<string,int>m;
        for(int i=0;i<wordList.size();i++){
            m[wordList[i]]++;
        }
        queue<string>q;
        q.push(startWord);
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            ans++;
            while(size--){
                string s=q.front();
                q.pop();
                if(s==targetWord){
                    return ans;
                }
                m.erase(s);
                for(int i=0;i<s.length();i++){
                    char r=s[i];
                    for(int c='a';c<='z';c++){
                        s[i]=c;
                        if(m.find(s)!=m.end()){
                            q.push(s);
                        }
                    }
                    s[i]=r;
                }
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends