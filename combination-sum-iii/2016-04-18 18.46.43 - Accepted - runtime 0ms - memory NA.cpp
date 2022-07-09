namespace numbers {

    /* cnted 是一个递增的数组
     * pair first 为数值；pair sencond 为数量(假设均>=1)
     */
    vector< vector<int> > _unique_sum_fixed_size(vector<pair<int,int> >& cnted, int startIdx, int dest, int depth) {
        vector< vector<int> > res;
        
        pair<int,int> & cp = cnted[startIdx];
        if (depth == 0) {
            if (dest == 0) {
                vector<int> can;
                res.push_back(can);
            }
            return res;
        }
        if (startIdx >= cnted.size()) return res;
        if (depth == 1) {
            int endIdx = cnted.size() - 1;
            while (startIdx <= endIdx) {
                int m = (startIdx + endIdx) / 2;
                int d = cnted[m].first - dest;
                if (d == 0) {
                    vector<int> can;
                    can.push_back(dest);
                    res.push_back(can);
                    break;
                } else if (d < 0) {
                    startIdx = m + 1;
                } else {
                    endIdx = m - 1;
                }
            }
            
            return res;
        }
        if (cp.first * depth > dest) {
            return res;
        }
        if (cnted[cnted.size() - 1].first * depth < dest) {
            return res;
        }
        for (int c= min(cp.second, depth); c>=0; c--) {
            vector< vector<int> > subres = _unique_sum_fixed_size(cnted, startIdx + 1, dest - cp.first * c, depth - c);
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
    vector<vector<int>> combinationSum3(int k, int target) {
        vector< pair<int,int> > cnted;
        for (int c=1; c<10; c++) {
            cnted.push_back(make_pair(c, 1));
        }
        return numbers::_unique_sum_fixed_size(cnted, 0, target, k);
    }
};