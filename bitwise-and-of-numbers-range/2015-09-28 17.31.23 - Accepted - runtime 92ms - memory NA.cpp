class Solution {
public:
    int singleBitwiseAnd(int m, int n, int p) {
        long long len = 1;
        len = (len << p);
        long long mod = (len << 2);
        if ((m / mod) != (n / mod)) {
            return 0;
        }
        
        int rem = m % mod;
        int ren = n % mod;
        int type = rem / len;
        if (type != (ren / len)) {
            return 0;
        }
        
        if (type == 0) return 0;
        if (type == 1) {
            return 1;
        }
        if (type == 2) {
            return 0;
        }
        if (type == 3) {
            return 1;
        }
        return 0;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        int r=0;
        int bitp = 0;
        for (; bitp<32; bitp++) {
            r ^= (singleBitwiseAnd(m, n, bitp) << bitp);
        }
        return r;
    }
    
};
