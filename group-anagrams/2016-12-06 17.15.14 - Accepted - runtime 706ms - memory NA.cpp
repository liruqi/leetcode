class Solution {
public:
    vector< vector<int> > cnts;
    map<int, vector<int> > lens; 
    
    int findAnagrams(string str) {
        vector<int> cnt(26, 0);
        for (int i=0; i<str.size();i++) cnt[str[i]-'a'] += 1;
        map<int, vector<int> >::iterator it = lens.find(str.size());
        if (it == lens.end()) {
            vector<int> l(1, cnts.size());
            lens[str.size()] = l;
            cnts.push_back(cnt);
            return -1;
        } else {
            vector<int> idxs = it->second;
            for (int i=0; i<idxs.size(); i++) {
                if (equal(cnt.begin(), cnt.end(), cnts[idxs[i]].begin())) {
                    it->second.push_back(idxs[i]);
                    return idxs[i];
                }
            }
            it->second.push_back(cnts.size());
            cnts.push_back(cnt);
            return -1;
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        cnts.clear();
        lens.clear();
        for (int i=0; i<strs.size(); i++) {
            int idx = findAnagrams(strs[i]);
            if (idx < 0) {
                vector<string> sa;
                sa.push_back(strs[i]);
                ret.push_back(sa);
            } else {
                ret[idx].push_back(strs[i]);
            }
        }
        return ret;
    }
};