class Solution {
public:
    vector<string>ans;
    void fun(int x,string &s,string path,long prev,long res,int target){
        if(x==s.length()){
            if(res==target){
                ans.push_back(path);
            }
            return;
        }
        long temp=0;
        string g="";
        for(int i=x;i<s.length();i++){
            if(i>x && s[x]=='0'){
                break;
            }
            temp=temp*10+(s[i]-'0');
            g=g+s[i];
            if(x==0){
                fun(i+1,s,path+g,temp,temp,target);
            }
            else{
             fun(i+1,s,path+'+'+g,temp,res+temp,target);
            fun(i+1,s,path+'-'+g,-temp,res-temp,target);
            fun(i+1,s,path+'*'+g,temp*prev,res-prev+prev*temp,target);   
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        ans.clear();
        fun(0,num,"",0,0,target);
        return ans;
    }
};