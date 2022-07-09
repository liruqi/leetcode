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
        vector<Interval> ret;
        int state = 0;
        int begin, end;
        for (vector<Interval>::iterator it=intervals.begin(); it!=intervals.end(); it++) {
            
            if (state == 0) {
                if (it->end < newInterval.start) {
                    ret.push_back(*it);
                    continue;
                }
                
                if (newInterval.end < it->start) {
                    ret.push_back(newInterval);
                    ret.push_back(*it);
                    state = 2;
                    continue;
                }
                begin = min(newInterval.start, it->start);
                end = max(it->end, newInterval.end);
                state = 1;
                continue;
            }
            
            if (state == 1) { //matching stage
                if (it->end < newInterval.end) {
                    continue;
                }
                
                if (it->start > newInterval.end) {
                    ret.push_back(Interval(begin, end));
                    ret.push_back(*it);
                } else {
                    ret.push_back(Interval(begin, it->end));
                }
                state = 2;
                continue;
            }
            
            if (state == 2) ret.push_back(*it);
        }
        
        if (state == 0) ret.push_back(newInterval);
        else if (state == 1) ret.push_back(Interval(begin, end));
        return ret;
    }
};