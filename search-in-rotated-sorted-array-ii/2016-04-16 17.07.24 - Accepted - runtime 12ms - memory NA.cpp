
class Solution {
public:
    size_t inc_prefix(vector<int>& nums) {
        vector< pair<int,int> > cnted;
        if (nums.size() == 0) {
            return 0;
        }
        cnted.push_back(make_pair(nums[0],1));
        for (size_t i=1; i<nums.size(); i++) {
            pair<int,int> & top = cnted[cnted.size() - 1];
            if (top.first == nums[i]) {
                top.second += 1;
            } else if (top.first < nums[i]) {
                cnted.push_back(make_pair(nums[i],1));
            } else {
                return i;
            }
        }
        return nums.size();
    }
    bool search(vector<int>& nums, int target) {
        size_t prefixlen = inc_prefix(nums);
        vector<int>::iterator p = lower_bound(nums.begin(), nums.begin() + prefixlen, target);
        if (p != nums.end() && *p == target) {
            cout << "prefix" << prefixlen << endl;
            return true;
        }
        vector <int> suffix(nums.begin() + prefixlen, nums.end());
        p = lower_bound(suffix.begin(), suffix.end(), target);
        if (p != suffix.end() && *p == target) {
            cout << "suffix " << prefixlen << endl;
            return true;
        }
        return false;
    }
};