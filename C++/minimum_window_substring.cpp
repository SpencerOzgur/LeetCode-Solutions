class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()){return "";}
        unordered_map<char, int> window; unordered_map<char, int> cntT;

        for (char c : t){
            if (!cntT.contains(c)){cntT[c] = 0;}
            cntT[c]++;
        }

        int l = 0;
        int have = 0; int need = t.size();
        pair<int, int> res = {-1, -1}; int resLen = INT_MAX;

        for (int r = 0; r < s.size(); r++){
            if(!window.contains(s[r])){window[s[r]] = 0;}
            window[s[r]]++;
            have += (window[s[r]] <= cntT[s[r]]) ? 1 : 0;

            while (have == need){
                if (r - l + 1 < resLen){
                    res.first = l; res.second = r;
                    resLen = r - l + 1;
                }
                window[s[l]]--;
                if (cntT.contains(s[l]) && window[s[l]] < cntT[s[l]]){have--;}
                l++;
            }
        }

        l = res.first; int r = res.second;
        return (resLen != INT_MAX) ? s.substr(l, r - l + 1) : "";
    }
};
