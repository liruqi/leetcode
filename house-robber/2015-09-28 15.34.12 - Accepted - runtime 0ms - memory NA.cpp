class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp0(1,0);
        vector<int> dp1(1,nums[0]);
        for (int i=1; i<nums.size(); i++) {
            int v0 = max(dp0[i-1], dp1[i-1]);
            int v1 = max(dp0[i-1] + nums[i], dp1[i-1]);
            dp0.push_back(v0);
            dp1.push_back(v1);
        }
        int li = nums.size() - 1;
        return max(dp0[li], dp1[li]);
    }
};