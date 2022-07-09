class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left=0;
        int right=n - 1;
        
        while(left<right) {
            int m = (left+right) / 2;
            if (A[m]>=target) {
                right = m;
            } else {
                left = m+1;
            }
        }
        vector<int> ret;
        if (A[left] != target) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        } 
        ret.push_back(left);
        
        left = 0;
        right=n - 1;
        while(left<right) {
            int m = (left+right+1) / 2;
            if (A[m]<=target) {
                left = m;
            } else {
                right = m-1;
            }
        }
        ret.push_back(left);
        return ret;
    }
};