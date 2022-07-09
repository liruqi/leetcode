public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashSet<Integer> s = new HashSet<Integer>();
        int i = 0;
        for (; i<nums.length && i<=k; i++) {
            if (s.contains(nums[i])) return true;
            s.add(nums[i]);
        }
        int b = 0;
        for (; i<nums.length; i++) {
            s.remove(nums[b]);
            b++;
            if (s.contains(nums[i])) return true;
            s.add(nums[i]);
        }
        return false;
    }
}