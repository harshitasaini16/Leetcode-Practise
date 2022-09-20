class Solution {
public:
    string intToRoman(int num) {
        string a[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int b[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int x=0;
        string ans="";
        while(num>0){
            if(num<b[x]){
                x++;
            }
            else{
                ans+=a[x];
                num-=b[x];
            }
        }
        return ans;
    }
};