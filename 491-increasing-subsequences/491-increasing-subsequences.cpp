class Solution {
public:
    void solving(vector<int>& nums, vector<vector<int>>& output, vector<int>& temp, int index){
        if(index >= nums.size()){
            if(temp.size() > 1)
                output.push_back(temp);
            return;
        }
        if(index==0 || temp.size()==0 || nums[index] >= temp[temp.size()-1]){
            temp.push_back(nums[index]);
            solving(nums, output, temp, index+1);
            temp.pop_back();
        }
        if(temp.size()==0 || temp[temp.size()-1]!=nums[index]){
            solving(nums, output, temp, index+1);
        }
}
	
vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp;
        solving(nums, output, temp, 0);
        return output;
}
};