class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rightProd(nums.size(), 1);
        vector<int> leftProd(nums.size(), 1);
        vector<int> res;

        for (int i=1; i<nums.size(); i++){
            leftProd[i] = leftProd[i - 1] * nums[i - 1];
            rightProd[nums.size() - 1 - i] = rightProd[nums.size() - i] * nums[nums.size() - i];
        }

        for (int i=0; i < nums.size(); i++){
            res.push_back(leftProd[i] * rightProd[i]);
        }

        return res;
    }
};
