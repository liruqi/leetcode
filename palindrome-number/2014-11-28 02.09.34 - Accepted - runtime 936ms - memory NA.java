public class Solution {
    public boolean isPalindrome(int x) {
        long y = 0;
        long xx = x;
        while (x > 0) {
            int d = x % 10;
            x /= 10;
            y *= 10;
            y += d;
        }
        
        return xx == y;
    }
}