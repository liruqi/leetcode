public class Solution {
    public int reverse(int x) {
        long a = x; 
        String ds = "" + (x>=0 ? a : -a);
        ds = new StringBuilder(ds).reverse().toString();
        a = ((x>=0 ? 1 : -1) * Long.parseLong(ds));
        if (a < Integer.MIN_VALUE || a > Integer.MAX_VALUE) return 0;
        return (int) a;
    }
}