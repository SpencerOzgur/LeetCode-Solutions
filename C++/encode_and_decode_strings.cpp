class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";

        for (string s : strs){
            res += to_string(s.size()) + '#' + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;

        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }

            int wordLen = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, wordLen));
            i = j + 1 + wordLen;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
