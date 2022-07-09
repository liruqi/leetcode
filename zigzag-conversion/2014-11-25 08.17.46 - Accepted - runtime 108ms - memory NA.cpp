
class Solution {
public:
    string convert(string s, int nRows) {
        int mod = 2*nRows - 2;
        if (mod <= 0)return s;

        char* buf = new char[s.size()];
        int bufsz = 0;
        for(int r=0; r<nRows; r++) {
            
            int m2 = mod - r;
            
            for(int i=r; i<s.size(); i+=mod) {
                buf[bufsz++] = s[i];
                int idx = i + m2 - r;
                if (r>0 && m2 != r) if (idx < s.size()) buf[bufsz++] = s[i + m2 - r];
            }
        }
        string ret(buf, buf+bufsz);
        return ret;
    }
};

