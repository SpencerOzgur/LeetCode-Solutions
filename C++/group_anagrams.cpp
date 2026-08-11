class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> wordMap;
        vector<vector<string>> res;

        for (string s : strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            wordMap[sortedS].push_back(s);
        }

        for (auto&[key, val] : wordMap){
            vector<string> cur;
            for (string s : val){
                cur.push_back(s);
            }

            res.push_back(cur);
        }

        return res;
    }
};
