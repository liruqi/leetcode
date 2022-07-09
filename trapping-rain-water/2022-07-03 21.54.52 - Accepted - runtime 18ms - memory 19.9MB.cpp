class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        
        long sum=0;
        int maxh = 0;
        int sz = 0;
        int barArea = 0;
        
        pair<int, int> inc = make_pair(-1, 0);
        for (long j = 0; j<height.size(); j++) {
            if (height[j] > maxh) {
                maxh = height[j];
                if (sz > 0) {
                    sum += inc.second * (j - inc.first - 1);
                    sum -= barArea;
                    barArea = 0;
                }
                sz += 1;
                //printf("%d %d %d %d\n", j, sum, barArea, sz);
                inc= make_pair(j, height[j]);
            } else {
                barArea += height[j];
            }
        }
        
        pair<int, int> rinc = make_pair(0, 0); ;
        sz = 0;
        maxh = 0;
        barArea = 0;
        for (long j = height.size() - 1; j>=0; j--) {
            if (height[j] > maxh) {
                maxh = height[j];
                if (sz > 0) {
                    sum += rinc.second * (rinc.first - j - 1);
                    sum -= barArea;
                    barArea = 0;
                }
                sz += 1;
                rinc = make_pair(j, height[j]);
                //printf("%d %d %d %d\n", j, sum, barArea, sz);

            } else {
                barArea += height[j];
            }
        }
        // count the middle area
        if (sz > 0) {
            
        for (long j = inc.first; j<rinc.first; j+=1) {
            sum += (inc.second - height[j]);
        }
            
        }
        return sum;
    }
};