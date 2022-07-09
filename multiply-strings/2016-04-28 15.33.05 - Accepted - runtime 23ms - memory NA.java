import java.math.BigInteger;

public class Solution {
    public String multiply(String num1, String num2) {
        BigInteger ans = new BigInteger(num1).multiply( new BigInteger(num2) );
        return ans.toString();
    }
}