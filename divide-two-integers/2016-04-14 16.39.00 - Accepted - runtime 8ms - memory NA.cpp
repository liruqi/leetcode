class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        long long res = (long long) dividend / (long long)divisor;
        if (res > INT_MAX || res < INT_MIN) return INT_MAX;
        return res;
    }
};