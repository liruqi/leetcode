class Solution {
public:
    int characterReplacement(string s, int k) {
        int chcnt[128];
        std::fill(chcnt+'A', chcnt+'A'+26, 0);
        int start=0;
        int ret=0;
        int sz = 0;
        for (int i=0; i<s.size(); i++) {
            int ch = s[i];
            sz+=1;
            chcnt[ch]+=1;
            int op = sz - *std::max_element(chcnt+'A', chcnt+'A'+26);
            while (op > k) {
                int startCh = s[start];
                start+=1;
                sz -= 1;
                chcnt[startCh] -= 1;
                op = sz - *std::max_element(chcnt+'A', chcnt+'A'+26);
            }
            ret = max(ret ,sz);
        }
        return ret;
    }
};