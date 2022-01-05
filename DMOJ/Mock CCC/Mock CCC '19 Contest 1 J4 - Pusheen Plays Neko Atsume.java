import java.util.*;

import java.io.*;

public class test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		
		int N = readInt(); 
		Map<String, Integer> hm = new HashMap();
		
		for (int i=0; i<N; i++) {
			String S = readLine();
			hm.put(S, hm.getOrDefault(S, 0)+1);
		}
		
		String arr[] = {"Deluxe Tuna Bitz", "Bonito Bitz", "Sashimi", "Ritzy Bitz"};
		
		while (!hm.isEmpty()) {
			String food = ""; int mx = 0;
			for (String s : arr) {
				if (!hm.containsKey(s)) continue;
				if (hm.get(s)>mx) {
					food = s; mx = hm.get(s);
				}
			}
			System.out.println(food + " " + mx);
			hm.remove(food);
		}
		
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