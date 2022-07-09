class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        
        long sum=0;
        int maxh = 0;
        int sz = 0;
        int barArea = 0;
        
                vector< pair<int, int> > inc;
        for (long j = 0; j<height.size(); j++) {
            if (height[j] > maxh) {
                maxh = height[j];
                if (sz > 0) {
                    sum += inc[sz - 1].second * (j - inc[sz - 1].first - 1);
                    sum -= barArea;
                    barArea = 0;
                }
                sz += 1;
                //printf("%d %d %d %d\n", j, sum, barArea, sz);
                inc.push_back(make_pair(j, height[j]));
            } else {
                barArea += height[j];
            }
        }
        
        vector< pair<int, int> > rinc;
        sz = 0;
        maxh = 0;
        barArea = 0;
        for (long j = height.size() - 1; j>=0; j--) {
            if (height[j] > maxh) {
                maxh = height[j];
                if (sz > 0) {
                    sum += rinc[sz - 1].second * (rinc[sz - 1].first - j - 1);
                    sum -= barArea;
                    barArea = 0;
                }
                sz += 1;
                rinc.push_back(make_pair(j, height[j]));
                //printf("%d %d %d %d\n", j, sum, barArea, sz);

            } else {
                barArea += height[j];
            }
        }
        // count the middle area
        if (inc.size() > 0) {
            
        for (long j = inc[inc.size() - 1].first; j<rinc[rinc.size() - 1].first; j+=1) {
            sum += (inc[inc.size() - 1].second - height[j]);
        }
            
        }
        return sum;
    }
};