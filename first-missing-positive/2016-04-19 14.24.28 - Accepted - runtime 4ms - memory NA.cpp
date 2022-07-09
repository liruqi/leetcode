class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> cnt(nums.size(), 0);
        for (int v : nums) {
            if (v > 0) {
                if (v <= sz) {
                    cnt[v - 1] += 1;
                }
            }
        }
        for (int i = 0; i<sz; i++) {
            if (cnt[i] == 0) {
                return i + 1;
            }
        }
        return sz + 1;
    }
};