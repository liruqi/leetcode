import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.Collections;


class Solution {
    public static int EMPTY_INDEX = -1;
    
    TreeSet<?>[] graph;
    int[] visited;
    int[] charSet = new int[256];
    char[] charArr;
    public int addEdge(Integer x, Integer y) {
        if (graph[x] == null) {
            graph[x] = new TreeSet<Integer>();
        }
        ((TreeSet<Integer>)graph[x]).add(y);
        return 0;
    }

    public int dfs(int x, int gid) {
        visited[x] = gid;
        charSet[(int)charArr[x]] += 1;
        if (graph[x] == null) return 0;

        for (Integer i : (TreeSet<Integer>)graph[x]) {
            if (EMPTY_INDEX == visited[i]) {
                dfs(i, gid);
            }
        }
        return 1;
    }
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        graph = new TreeSet<?>[s.length()];
        visited = new int[s.length()];
        Arrays.fill(visited, EMPTY_INDEX);
        for (List<Integer> lx : pairs) {
            Integer y=lx.get(0);
            Integer z=lx.get(1);
            if (y == z) continue;
            addEdge(y, z);
            addEdge(z, y);
        }
        charArr = s.toCharArray();
        for (int i=0; i<s.length(); i++) {
            if (EMPTY_INDEX == visited[i]) {
                Arrays.fill(charSet, 0);
                dfs(i, i);

                char k='a';
                // System.out.print("\n" + i + " -> ");

                for (int j=0; j<visited.length; j++) if (visited[j] == i)
                {
                    // System.out.print(j + " ");

                    while (charSet[k] == 0 && k<'z') {
                        k += 1;
                    }
                    charArr[j] = k;
                    charSet[k] -= 1;
                }
            }
        }
        return String.valueOf(charArr);
    }

}