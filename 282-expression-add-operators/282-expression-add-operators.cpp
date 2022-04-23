class Solution {
public:
    vector<string>ans;
    void fun(int x,string &s,string path,long res,long prev,int target){
        if(x==s.length()){
            if(res==target){
                ans.push_back(path);
            }
            return;
        }
        string ns="";
        long temp=0;
        for(int j=x;j<s.length();j++){
            if(j>x && s[x]=='0'){
                break;
            }
            ns+=s[j];
            temp=temp*10+(s[j]-'0');
            if(x==0){
                fun(j+1,s,path+ns,temp,temp,target);
            }
            else{
                fun(j+1,s,path+"+"+ns, res+temp, temp,target);
                fun(j+1,s,path+"-"+ns, res-temp, -temp,target);
                fun(j+1,s,path+"*"+ns, res-prev+prev*temp, prev*temp,target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        fun(0,num,"",0,0,target);
        return ans;
    }
};  