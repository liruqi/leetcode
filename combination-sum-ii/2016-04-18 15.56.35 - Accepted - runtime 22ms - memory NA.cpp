namespace numbers {
    vector< pair<int,int> > sort_uniq_c(vector<int>& nums) { // sort | uniq -c
        vector< pair<int,int> > cnted;
        if (nums.size() == 0) {
            return cnted;
        }
        sort(nums.begin(), nums.end());
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
/* cnted 是一个递增的数组
     * pair first 为数值；pair sencond 为数量(假设均>=1)
     * 无长度限制
     */
    vector< vector<int> > _unique_sum(vector<pair<int,int> >& cnted, int startIdx, int dest) {
        vector< vector<int> > res;
        if (dest == 0) {
            vector<int> can;
            res.push_back(can);
            return res;
        }
        
        if (startIdx >= cnted.size()) return res;
        pair<int,int> & cp = cnted[startIdx];
        if (cp.first > dest) return res;
        for (int c= cp.second; c>=0; c--) {
            vector< vector<int> > subres = _unique_sum(cnted, startIdx + 1, dest - cp.first * c);
            for (int subi=0; subi<subres.size(); subi++) {
                vector<int> can = subres[subi];
                can.insert(can.begin(), c, cp.first);
                res.push_back(can);
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector< pair<int,int> > cnted = numbers::sort_uniq_c(candidates);
        return numbers::_unique_sum(cnted, 0, target);
    }
};