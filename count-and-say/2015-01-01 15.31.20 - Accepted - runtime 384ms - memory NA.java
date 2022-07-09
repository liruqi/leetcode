public class Solution {
    public String countAndSay(int n) {
        String ret = "1";
        for (int i=1; i<n; i++) {
            ret = transform(ret);
        }
        return ret;
    }
    
    public String transform(String s) {
        char c = 0;
        int cnt = 0;
        StringBuffer ret = new StringBuffer();
        for (int i=0; i<s.length(); i++) {
            if (c == s.charAt(i)) cnt++;
            else {
                if (cnt > 0) ret .append(""+ cnt + String.valueOf(c));
                c = s.charAt(i);
                cnt = 1;
            }
        }
        if (cnt > 0) ret .append(""+ cnt + String.valueOf(c));
        return ret.toString();
    }
}