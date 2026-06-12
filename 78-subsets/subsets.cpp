class Solution {
public:
    void Inserter(int index, vector<int>& nums, vector<int>& subArray,
                  vector<vector<int>>& result) {
        auto it = find(result.begin(), result.end(), subArray);
        if (it == result.end())
            result.push_back(subArray);
        if (index == nums.size()) {
            return;
        }
        subArray.push_back(nums[index]);
        Inserter(index + 1, nums, subArray, result);
        subArray.pop_back();
        Inserter(index + 1, nums, subArray, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int index = 0;
        vector<int> subArray;
        Inserter(index, nums, subArray, result);
        return result;
    }
};