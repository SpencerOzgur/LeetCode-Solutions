class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> charToInd;

        for (int i=0; i<numbers.size(); i++){
            if (charToInd.contains(target - numbers[i])){
                vector<int> res = {charToInd[target - numbers[i]], i + 1};
                return res;
            }
            charToInd[numbers[i]] = i + 1;
        }
        vector<int> res;
        return res;
    }
};
