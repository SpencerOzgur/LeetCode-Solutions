class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> s;

        for (int i=0; i<heights.size(); i++){
            int begin = i;
            while (!s.empty() && s.top().first > heights[i]){
                res = max(res, (i-s.top().second) *  s.top().first);
                begin = s.top().second;
                s.pop();
            }

            pair<int, int> p = {heights[i], begin};
            s.push(p);
        }

        while (!s.empty()){
            res = max(res, ((int) heights.size()-s.top().second) * s.top().first);
            s.pop();
        }
        return res;
    }
};
