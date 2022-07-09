class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int can = 0;
        int ret = nums.size();
        while (start <= end && start<nums.size() && end < nums.size()) {
            while (can < s) {
                can += nums[end];
                end += 1;
                if (end >= nums.size()) { if (can < s && start == 0) return 0; break;}
            }
            while (can - nums[start] >= s) {
                can -= nums[start];
                start += 1;
            }
            cout<< start << end << endl;
            ret = min(end - start, ret);
            can -= nums[start];
            start += 1;
        }
        return ret;
    }
};