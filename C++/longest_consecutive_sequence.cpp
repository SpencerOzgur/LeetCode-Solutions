class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (auto& n : numSet){
            if (numSet.contains(n - 1)){
                continue;
            }

            int cur = 1;
            int i = n;
            while (numSet.contains(i + 1)){
                i++;
                cur++;
            }

            res = max(res, cur);
        }
        return res;
    }
};
