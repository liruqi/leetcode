/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> sorted;
        int state = 0;
        for (vector<Interval>::iterator it=intervals.begin(); it!=intervals.end(); it++) {
            if (state) sorted.push_back(*it);
            if (it->start > newInterval.start) {
                sorted.push_back(newInterval);
                sorted.push_back(*it);
                state = 1;
                continue;
            }
            if (it->start == newInterval.start) {
                sorted.push_back(Interval(it->start, max(it->end, newInterval.end) ));
                state = 1;
                continue;
            }
            sorted.push_back(*it);
        }
        if (state == 0) sorted.push_back(newInterval);
        
        vector<Interval> merged;
        

        for (vector<Interval>::iterator it=sorted.begin(); it!=sorted.end(); it++) {
            if (merged.empty()) {
                merged.push_back(*it);
                continue;
            }
            
            if (merged.back().end < it->start) {
                merged.push_back(*it);
                continue;
            }
            
            merged.back().end = max(merged.back().end, it->end);
        }

        return merged;
    }
};