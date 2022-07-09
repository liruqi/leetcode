class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sums;
        
        int s = 0;
        for(int i=0; i<nums.size(); i++) {
            sums.push_back(s);
            s+=nums[i];
        }
        sums.push_back(s);
        vector<int> maxAfterIndex(nums.size());
        int mval = sums[sums.size() - 1];
        int ans = mval;

        for (int i=sums.size() - 2; i>=0; i--) {
            maxAfterIndex[i] = mval;
            if (sums[i] > mval) mval = sums[i];
        }
        for (int i=0; i<maxAfterIndex.size(); i++) {
            int can = maxAfterIndex[i] - sums[i];
            if (can > ans) ans = can; 
        }
        return ans;
    }
};