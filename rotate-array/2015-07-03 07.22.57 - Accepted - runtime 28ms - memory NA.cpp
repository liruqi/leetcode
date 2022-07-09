class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> rot;
        int N = nums.size();
        k = k%N;
        for(int i=0;i<N;i++) {
            rot.push_back( nums[(i+N-k)%N] );
        }
        nums = rot;
    }
};