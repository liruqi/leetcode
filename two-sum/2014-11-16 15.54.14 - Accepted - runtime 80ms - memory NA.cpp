class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> m; 
        vector<int> ret;
        for(int i=0;i<numbers.size();i++) {
            int a = numbers[i];
            int b = target - a;
            map<int,int>::iterator it = m.find(b);
            if (it == m.end()) {
                m[a] = i;
            } else {
                ret.push_back(it->second + 1);
                ret.push_back(i + 1);
                return ret;
            }
        }
        return ret;
    }
};