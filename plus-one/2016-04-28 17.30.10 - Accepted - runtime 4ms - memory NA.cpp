class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i=digits.size() - 1; i>=0; i--) {
            if (digits[i] + carry > 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        digits.insert(digits.begin(), carry);
        return digits;
    }
};