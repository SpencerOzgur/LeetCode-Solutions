class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0; int smallest = prices[0];
        for (int p : prices){
            res = max(p - smallest, res);
            smallest = min(smallest, p);
        }
        return res;
    }
};
