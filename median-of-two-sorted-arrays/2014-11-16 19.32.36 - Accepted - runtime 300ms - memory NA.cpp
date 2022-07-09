
class Solution {
public:
    int findK(int* A, int m, int* B, int n, int k) {
        int pa=0;
        int pb=0;
        while (k >= 0) {
            if (pa >= m) {
                return B[pb + k];
            }
            if (pb >= n) {
                return A[pa + k];
            }
            if (k == 0) {
                return min(A[pa], B[pb]);
            }
            int pan = min(m - 1, pa + k/2);
            int pbn = pb + (k - 1) - (pan - pa);
            if (pbn >= n) {
                int diff = pbn - (n - 1);
                pbn = n - 1;
                pan += diff;
            }
            if (A[pan] < B[pbn]) {
                k -= (pan - pa) + 1;
                pa = pan + 1;
            } else {
                k -= (pbn - pb) + 1;
                pb = pbn + 1;
            }
        }
        return 0;
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m+n <= 0) { // error
            return 0;
        }
        if ((m+n) & 1) {
            return findK(A, m, B, n, (m+n)/2);
        }
        
        int sum = findK(A, m, B, n, (m+n)/2 - 1) + findK(A, m, B, n, (m+n)/2);
        return sum / 2.0;
    }

};
