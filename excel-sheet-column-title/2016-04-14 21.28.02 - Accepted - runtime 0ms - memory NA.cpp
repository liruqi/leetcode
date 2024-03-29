
#define STRINGS_CHARSET_SZ 256

namespace strings {
    
    std::string longest_common_prefix(std::string f, std::string s) {
        int i=0;
        for (; i<f.length() && i<s.length() && f[i]==s[i]; i++);
        return f.substr(0, i);
    }
    
    std::string longest_common_prefix(vector<std::string>& strs) {
        int i=1;
        if (strs.size() == 0) return "";
        std::string result = strs[0];
        for (; i<strs.size(); i++)
            result = longest_common_prefix(result, strs[i]);
        return result;
    }
    
    bool is_closed_parentheses(string s, char *mp) {
        stack<char> stk;
        for(char ch : s) {
            if (mp[ch] > 0) {
                if (stk.size() > 0 && mp[ch]  == stk.top()) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(ch);
            }
        }
        
        return (stk.size() == 0);
    }
    
    // mp: char to int
    long to_long(string s, int *mp, long base) {
        long ret = 0;
        for(char ch : s) {
            ret = mp[ch] + ret * base;
        }
        return ret;
    }
    
    long excel_column_to_long(string s) {
        int mp[STRINGS_CHARSET_SZ];
        memset(mp, 0, sizeof(mp));
        for (char ch='A'; ch <='Z'; ch++) mp[ch] = ch - 'A' + 1;
        return to_long(s, mp, 26);
    }
    
    // mp: int to char
    string from_long(int n, char *mp, long base, int zero) {
        vector< pair<long,long> > plist;
        long last = 0;
        long powr = 1;
        string s;
        // A -> 1 zero
        // AA -> 27 zero + base
        // AAA ->
        for (int len = 1; last < n; len++) {
            s.push_back (mp[zero]);
            last = excel_column_to_long(s);
            plist.push_back(make_pair(last, powr));
            powr *= base;
        }
        
        string ret;
        for (int idx = plist.size() - 1; idx>=0; idx--) {
            if (plist[idx].first > n) continue;
            long val = n - plist[idx].first;
            long dgt = (val / plist[idx].second);
            char ch = mp[dgt + zero];
            ret.push_back(ch);
            n -= (dgt + zero) * plist[idx].second;
        }
        return ret;
    }
    
    string long_to_excel_column(long n) {
        char mp[STRINGS_CHARSET_SZ];
        memset(mp, 0, sizeof(mp));
        for (int ch=1; ch <=26; ch++) mp[ch] = ch + 'A' - 1;
        return from_long(n, mp, 26, 1);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return strings::longest_common_prefix(strs);
    }
    bool isValid(string s) {
        char mp[STRINGS_CHARSET_SZ];
        memset(mp, 0, sizeof(mp));
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';

        return strings::is_closed_parentheses(s, mp);   
    }
    string convertToTitle(int n) {
        return strings::long_to_excel_column(n);
    }
};
