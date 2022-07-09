public class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (k <= 1) {
            List<Integer> lst = new ArrayList<Integer>();
            if (n <= 9) {
            lst.add(n);
            ret.add(lst);
            }
            return ret;
        }
        for (int i=1; i<=9; i++) {
            int head = i;
            int kk = k - 1;
            int nn = n - k * head;
            if (nn <= 0) continue;
            List<List<Integer>> sub = combinationSum3(kk, nn);
            for (int j=0; j<sub.size(); j++) {
                List<Integer> asub = sub.get(j);
                ArrayList<Integer> lst = new ArrayList<Integer>();
                lst.add(head);
                int maxx = head;
                for (Integer itg : asub) {
                    lst.add(itg + head);
                    maxx = itg + head;
                }
                if (maxx <= 9)
                ret.add(lst);
            }
        }
        return ret;
    }
    
    
}