public class Solution {
    public boolean containsAlmostDuplicate(TreeSet<Long>s, long begin, long end) {
        Long flr = s.floor(end);
        if (flr == null) return false;
        return flr >= begin;
    }
    
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int tt) {
        k = (k>=0) ? k : (-k);
        //t = (t>=0) ? t : (-t);
        long t = tt;
        TreeSet<Long> s = new TreeSet<Long>();
        int i = 0;
        for (; i<nums.length && i<=k; i++) {
            if (containsAlmostDuplicate(s, nums[i] - t, nums[i] + t)) return true;
            s.add((long)nums[i]);
        }
        int b = 0;
        for (; i<nums.length; i++) {
            s.remove((long)nums[b]);
            b++;
            if (containsAlmostDuplicate(s, nums[i] - t, nums[i] + t)) return true;
            s.add((long)nums[i]);
        }
        return false;
    }
}