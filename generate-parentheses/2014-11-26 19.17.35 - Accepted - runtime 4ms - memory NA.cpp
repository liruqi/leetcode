class Solution {
public:
    vector<string> ret;
    char *par;
    int parlen;
    int n;
    vector<string> generateParenthesis(int nn) {
        ret.clear();
        n = nn;
        par = new char[2*n];
        parlen = 0;
        dfs(0,0);
        
        return ret;
    }
    void dfs(int l,int r) {
        if (l == n) {
            string s(par, par+2*n);
            if (r == n) { 
                ret.push_back(s);
                return;
            }
            par[l+r] = ')';
            dfs(l, r+1);
            return;
        }
        
        par[l+r] = '(';
        dfs(l+1, r);
        
        if (l > r) {
            par[l+r] = ')';
            dfs(l, r+1);
        }
    }
};