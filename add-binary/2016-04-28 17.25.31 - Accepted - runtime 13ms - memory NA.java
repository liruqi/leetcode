import java.math.BigInteger;

public class Solution {
    public String addBinary(String a, String b) {
        BigInteger ans = new BigInteger(a,2).add( new BigInteger(b,2) );
        return ans.toString(2);
    }
}
