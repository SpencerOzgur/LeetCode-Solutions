class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> charMap{
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s){
            if (charMap.contains(c) && (st.empty() || st.top() != charMap[c])){return false;}
            else if(charMap.contains(c)){st.pop();}
            else{st.push(c);}
        }

        return st.empty();
    }
};
