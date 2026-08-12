class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> alnum;

        for (char c : s){
            if (isdigit(c)){
                alnum.push_back(c);
            }

            else if (isalpha(c)){
                alnum.push_back(tolower(c));
            }
        }

        int l = 0;
        int r = alnum.size() - 1;

        while (l < r){
            if (alnum[l] != alnum[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
