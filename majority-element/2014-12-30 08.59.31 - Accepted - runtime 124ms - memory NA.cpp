class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int,int> cnt;
        for (int i=0;i<num.size();i++) {
            int val = num[i];
            if (cnt.find(val) == cnt.end()) cnt[val] = 1;
            else cnt[val] +=1;
        }
        int n = num.size();
        for (map<int,int>::iterator it=cnt.begin(); it!=cnt.end(); ++it) {
            if (it->second > (n/2)) return it->first;
        }
        return 0;
    }
};