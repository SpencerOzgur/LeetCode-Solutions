class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToInd;

        for (int i = 0; i < nums.size(); i++){
            if (numToInd.contains(target - nums[i])){
                vector<int> res = {numToInd[target - nums[i]], i};
                return res;
            }
            numToInd[nums[i]] = i;
        }

        return {};
    }
};
