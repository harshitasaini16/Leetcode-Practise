class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>v;
        if(nums.size()==0){
            return {};
        }
        int n=nums.size();
        string s="";
        bool f=false;
        int x;
        for(int i=0;i<n;i++){
            if(s==""){
                s=s+to_string(nums[i]);
                x=nums[i];
            }
            else{
                if(nums[i]==x+1){
                    x++;
                }
                else{
                    if(stoi(s)==x){
                        v.push_back(s);
                        s=to_string(nums[i]);
                        x=nums[i];
                    }
                    else{
                        s=s+"->";
                        s=s+to_string(x);
                        v.push_back(s);
                        s=to_string(nums[i]);
                        x=nums[i];
                    }
                }
            }
        }
        // cout<<s;
        if(stoi(s)==x){
            v.push_back(s);
            s="";
        }
        else{
            s=s+"->";
            s=s+to_string(x);
            v.push_back(s);
            s="";
        }
        return v;
    }
};