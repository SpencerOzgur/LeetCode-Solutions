class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0; int l = 0;
        unordered_map<char, int> window;

        for (int r = 0; r < s.size(); r++){
            if (!window.contains(s[r])){
                window[s[r]] = 0;
            }
            window[s[r]]++;
            int maxVal = INT_MIN;
            for (const auto& [k, v] : window){maxVal = max(maxVal, v);}
            
            while (maxVal + k < r - l + 1){
                window[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
