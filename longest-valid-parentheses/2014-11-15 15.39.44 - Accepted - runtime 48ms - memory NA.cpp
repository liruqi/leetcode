#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = longest(s, '(');
        reverse(s.begin(), s.end()); 
        return max(ret, longest(s, ')'));
    }

    int longest(string s,char c) {
        int left=0;
        int ret =0;
        int cnt =0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == c) left += 1; 
            else left -= 1;

            if (left >=0) {
                cnt += 1;
                if (left == 0) ret = max(ret, cnt);
            } else {
                left = 0; cnt = 0;
            }
        }
        return ret;
    }
};
