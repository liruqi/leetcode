public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rowcnt[][] = new int[matrix.length][];
        int colcnt[][] = new int[matrix.length][];
        int dp[][] = new int[matrix.length][];
        int ret = 0;
        for (int r=0; r<matrix.length; r++) {
        	
        	rowcnt[r] = new int[matrix[r].length];
        	colcnt[r] = new int[matrix[r].length];
        	dp[r] = new int[matrix[r].length];

        	int len = 0;
        	for (int c=0; c<matrix[r].length; c++) {
        		if (matrix[r][c] > 2) {
        			matrix[r][c] -= '0';
        		}
        		
        		if (matrix[r][c] > 0) {
        			len ++;
        		} else {
        			len = 0;
        		}
    			rowcnt[r][c] = len;
    			
    			if (r == 0) {
    				colcnt[r][c] = matrix[r][c];
    				dp[r][c] = matrix[r][c];
    			} else {
    				if (matrix[r][c] > 0) {
    					colcnt[r][c] = colcnt[r-1][c] + 1;
    					
    					if (c == 0) dp[r][c] = matrix[r][c];
    					else {
    						int can = dp[r-1][c-1] + 1;
    						can = Math.min(can, rowcnt[r][c]);
    						can = Math.min(can, colcnt[r][c]);
    						dp[r][c] = can;
    					}
    					
            		} else {
    					colcnt[r][c] = 0;
    					dp[r][c] = 0;
            		}
    			}
    			
    			ret = Math.max(ret, dp[r][c]);
        	}
        	
        }
        
        return ret * ret;
    }
}