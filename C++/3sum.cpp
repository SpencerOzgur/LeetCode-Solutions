class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<tuple<int, int, int>> seen;

        for (int i=0; i<nums.size(); i++){
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r){
                if (nums[i] + nums[l] + nums[r] == 0){
                    tuple<int, int, int> t = {nums[i], nums[l], nums[r]};
                    if (!seen.contains(t)){
                        vector<int> curVec = {get<0>(t), get<1>(t), get<2>(t)};
                        res.push_back(curVec);
                        seen.insert(t);
                    }

                    l++;
                }
                else if (nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }
                else{
                    r--;
                }
            }


        }

        return res;
    }
};
