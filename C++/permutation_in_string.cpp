class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> cnt1; unordered_map<int, int> cnt2;
        int l = 0;

        for (char c : s1){
            if (!cnt1.contains(c)){cnt1[c] = 0;}
            cnt1[c]++;
        } 

        for(int r = 0; r < s2.size(); r++){
            if (cnt1 == cnt2){return true;}

            if (!cnt2.contains(s2[r])){cnt2[s2[r]] = 0;}
            cnt2[s2[r]]++;

            if (r >= s1.size()){
                cnt2[s2[l]]--;
                if (cnt2[s2[l]] == 0){cnt2.erase(s2[l]);}
                l++;
            }
        }

        return cnt1 == cnt2;
    }
};
