class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        vector< pair<int, int> > rinc;
        int maxh = 0;
        for (long j = height.size() - 1; j>=0; j--) {
            if (height[j] > maxh) {
                maxh = height[j];
                rinc.push_back(make_pair(j, height[j]));
            }
        }
        
        maxh = 0;
        for (int i=0; i<height.size(); i++) {
            if (height[i] <= maxh) {
                continue;
            }
            maxh = height[i];
            
            for (int rinci = 0; rinci<rinc.size(); rinci ++) {
                pair<int, int> ln = rinc[rinci];
                if (i >= ln.first) {
                    break;
                }
                int can = (ln.first - i) * min(ln.second, height[i]);
                if (can > ret) ret = can;
            }
        }
        return ret;
    }
};
