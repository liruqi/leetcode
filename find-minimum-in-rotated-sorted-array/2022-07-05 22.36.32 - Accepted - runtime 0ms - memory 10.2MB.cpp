class Solution {
public:
    int findMin(vector<int>& nums) {
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
                return nums[i];
            }
        }
        return nums[0];
    }
};