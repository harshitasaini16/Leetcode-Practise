class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        vector<vector<int>>temp;
        for(int i=0; i<arr.size(); i++)
        {
            vector<int>z;
            z.push_back(abs(arr[i]-x));
            z.push_back(arr[i]);
            temp.push_back(z);
        }
        sort(temp.begin(), temp.end());
        for(int i=0; i<k; i++)
        {
            ans.push_back(temp[i][1]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};