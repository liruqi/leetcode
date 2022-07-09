class Solution {
public:

    vector< pair<int,int> > sort_uniq_c(vector<int>& nums) { // sort | uniq -c
        vector< pair<int,int> > cnted;
        if (nums.size() == 0) {
            return cnted;
        }
        
        cnted.push_back(make_pair(nums[0],1));
        for (int i=1; i<nums.size(); i++) {
            pair<int,int> & top = cnted[cnted.size() - 1];
            if (top.first == nums[i]) {
                top.second += 1;
            } else {
                cnted.push_back(make_pair(nums[i],1));
            }
        }
        return cnted;
    }
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        vector< pair<int,int> > sorted = sort_uniq_c(nums);
        for(pair<int,int> p : sorted) {
            nums[i] = p.first;
            i++;
        }
        return sorted.size();
    }
};