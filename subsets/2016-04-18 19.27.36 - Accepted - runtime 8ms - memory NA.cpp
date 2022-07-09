class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        long mask;
        long upper = 1 << nums.size();
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for (mask=0; mask < upper; mask ++) {
            vector<int> can;
            for(int b=0; b<n; b++) if((1<<b) & mask) can.push_back(nums[b]);
            ans.push_back(can);
        }
        return ans;
    }
};