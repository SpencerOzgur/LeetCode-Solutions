class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0; int r = height.size() - 1;
        int maxL = height[l]; int maxR = height[r];
        int res = 0;

        while (l < r){
            if (height[l] <= height[r]){
                l++;
                res += max(0, min(maxL, maxR) - height[l]);
                maxL = max(maxL, height[l]);
            }

            else{
                r--;
                res += max(0, min(maxL, maxR) - height[r]);
                maxR = max(maxR, height[r]);
            }
        }

        return res;
    }
};
