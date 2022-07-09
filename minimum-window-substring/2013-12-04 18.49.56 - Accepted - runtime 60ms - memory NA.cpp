#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string minWindow(string S, string T) {
        int charSet[256];
        std::fill(charSet, charSet+256, 0);
        for (int i=0;i<T.size();i++) charSet[T[i]] += 1;
        int charCnt[256];
        std::fill(charCnt, charCnt+256, 0);
        
        int tail = 0;
        int window = 0;
        string ret = "";
        int setCnt = 0;
        for (int i=0;i<S.size();i++) {
            char c = S[i];
            if (! charSet[c]) continue;
            charCnt[c] += 1;
            if (charCnt[c] <= charSet[c]) setCnt += 1;

            //cout<<"# "<<setCnt<<" "<<T.size()<<endl;
            if (setCnt >= T.size()) {
                // reduce window
                while (true) {
                    if (! charSet[S[tail]]) {
                        tail += 1;
                        continue;
                    }
                    if (charCnt[S[tail]] > charSet[S[tail]]) {
                        charCnt[S[tail]] -= 1;
                        tail += 1;
                        continue;
                    }
                    break;
                }
                //cout<<"# "<<tail<<" "<<i<<endl;
                
                int sz = i - tail + 1;
                if (ret.size() == 0) {
                    ret = S.substr(tail, sz);
                } else if (sz < ret.size()){
                    ret = S.substr(tail, sz);
                }
            }
        }
        return ret;
    }
};
