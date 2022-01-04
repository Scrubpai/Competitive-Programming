import java.util.*;
import java.io.*;
public class ccc07j3 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		
		Map<Integer, Integer> hm = new HashMap();
		hm.put(1, 100); hm.put(2, 500); hm.put(3, 1000); hm.put(4, 5000); hm.put(5, 10000); hm.put(6, 25000); 
		hm.put(7, 50000); hm.put(8, 100000); hm.put(9, 500000); hm.put(10, 1000000);
		double tot = 1691600;
		
		int n = readInt();
		for (int i=0; i<n; i++) {
			int x = readInt();
			tot -= hm.get(x);
		}
		
		tot/=(10-n);
		int b = readInt();
		if (b>tot) System.out.println("deal");
		else System.out.println("no deal");
	
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}