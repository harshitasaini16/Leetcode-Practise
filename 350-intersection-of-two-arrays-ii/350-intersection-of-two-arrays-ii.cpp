class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        vector<int>v;
        for(int j=0;j<nums2.size();j++){
            if(m[nums2[j]]>0){
                v.push_back(nums2[j]);
                m[nums2[j]]--;
            }
        }
        return v;
    }
};