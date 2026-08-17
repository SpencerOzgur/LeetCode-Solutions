class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int>& B = (nums1.size() > nums2.size()) ? nums1 : nums2;


        int total = A.size() + B.size();
        int half = total / 2;

        if (A.size() == 0){
            if (B.size() % 2 == 1){return B[half];}
            else{return (float)(B[half] + B[half - 1]) / 2;}
        }

        int l = -1; int r = A.size() - 1;

        while (true){
            int i = l + (r - l) / 2;
            int j = half - i - 2;

            int Aleft = (i >= 0) ? A[i] : INT_MIN;
            int Aright = (i + 1 < A.size()) ? A[i + 1] : INT_MAX;
            int Bleft = (j >= 0) ? B[j] : INT_MIN;
            int Bright = (j + 1 < B.size()) ? B[j + 1] : INT_MAX; 

            if (Aleft <= Bright && Bleft <= Aright){
                if (total % 2 == 1){return (float) min(Aright, Bright);}
                else{return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;}
            }

            else if(Aright < Bleft){l = i + 1;}
            else{r = i - 1;}
        }
    }
};
