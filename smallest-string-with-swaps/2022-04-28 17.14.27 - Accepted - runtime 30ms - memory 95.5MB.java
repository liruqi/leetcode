import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.Collections;


class Solution {
    
    class DSU {
        int[] parent;
        int[] size;
        
        DSU(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int getRootNode(int x) {
            if (x == parent[x]) return x;
            parent[x] = getRootNode(parent[x]);
            return parent[x];
        }
        
        void union(int x, int y) {
            int xR = getRootNode(x);
            int yR = getRootNode(y);
            if (xR == yR) return;
            if (size[xR] > size[yR]) {
                size[xR] += size[yR];
                parent[yR] = xR;
            } else {
                size[yR] += size[xR];
                parent[xR] = yR;
            }
        }
    }
    
    DSU dsu;
    Map<Integer, ArrayList<Integer>> indiceGroups;
    char[] charArr;

    public int updateIndiceGroups(int x) {
        Integer g = dsu.getRootNode(x);
        if (indiceGroups.containsKey(g)) {
            indiceGroups.get(g).add(x);
            return 0;
        }
        ArrayList<Integer> ts = new ArrayList<Integer>();
        ts.add(x);
        
        indiceGroups.put(g, ts);
        return ts.size();
    }
    
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        indiceGroups = new HashMap<Integer, ArrayList<Integer>>();
        dsu = new DSU(s.length());
        for (List<Integer> lx : pairs) {
            Integer y=lx.get(0);
            Integer z=lx.get(1);
            if (y == z) continue;
            dsu.union(z, y);
        }

        for (int x=0; x<s.length(); x++) {
            updateIndiceGroups(x);
        }

        charArr = s.toCharArray();
        for (Map.Entry<Integer,ArrayList<Integer>> entry : indiceGroups.entrySet()) {            
            List<Integer> igl = entry.getValue();
            // Collections.sort(igl);
            // System.out.println(igl);
            int[] charList = new int[256];
            Arrays.fill(charList, 0);
            for (Integer x : igl) {
                charList[(int)charArr[x]] += 1;
            }
            char k='a';
            for (int j=0; j<igl.size(); j++) {
                while (charList[k] == 0 && k<'z') {
                    k += 1;
                }
                charArr[ igl.get(j) ] = k;
                charList[k] -= 1;
            }
            // // System.out.println(charArr);
        }
        return String.valueOf(charArr);
    }

}