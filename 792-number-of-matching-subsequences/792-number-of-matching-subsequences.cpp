class Solution {
public:
int fun(vector<int>&arr,int prev){
int i=0,j=arr.size()-1;
int ans=INT_MAX;
while(i<=j){
int m=i+(j-i)/2;
if(arr[m]>prev){
ans=arr[m];
j=m-1;
}else{
i=m+1;
}
}
return ans;
}
int numMatchingSubseq(string s, vector<string>& arr) {
map<char,vector<int>>mp;
for(int i=0;i<s.length();i++){
mp[s[i]].push_back(i);
}
int ans=0;
for(auto x:arr){
int prev=-1;
bool f=true;
for(auto y:x){
if(mp.find(y)==mp.end()){
f=false;
break;
}else{
int k=fun(mp[y],prev);
// cout<<y<<" "<<k<<endl;
if(k==INT_MAX){
f=false;
break;
}
prev=k;
}
}
if(f==true){
ans++;
}
}
return ans;
}
};