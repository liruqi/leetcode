
public class Solution {
    List<String> ret;
    String[] ip = new String[4];
    
    public List<String> restoreIpAddresses(String s) {
        ret = new ArrayList<String> ();
        restore(0, s);
        return ret;
    }
    
    void restore(int ipsize, String s) {

        if (ipsize >= 4) {
        	if (s.length() > 0) return;
        	String ipstr = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
        	ret.add(ipstr);
        	return;
        }
        
        for (int i=1; i<=s.length() && i<4; i++) {
        	String ipsub = s.substring(0, i);
        	int ipnum = Integer.parseInt(ipsub);
        	
        	if ((i==1) 
        			|| (i==2 && ipnum>=10) 
        			|| (i==3 && ipnum >= 100 && ipnum<=255)) {
        		ip[ipsize] = ipsub;
        		restore(ipsize+1, s.substring(i));
        	}
        }
    }
}
