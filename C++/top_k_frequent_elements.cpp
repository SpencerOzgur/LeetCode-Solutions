class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        vector<pair<int, int>> pairings;
        vector<int> res;

        for (int i : nums){
            cnt[i]++;
        }

        for (auto& [key, val] : cnt){
            pair<int, int> p = {val, key};
            pairings.push_back(p);
        }

        sort(pairings.rbegin(), pairings.rend());

        for (int i = 0; i < pairings.size(); i++){
            res.push_back(pairings[i].second);
            if (res.size() == k){
                break;
            }
        }

        return res;
    }
};
